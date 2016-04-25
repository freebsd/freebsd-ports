# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fbreader
PORTVERSION=	0.99.6
DISTVERSIONSUFFIX=	-freebsdport
PORTREVISION=	2
CATEGORIES=	deskutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Powerful e-book reader

LICENSE=	GPLv2+

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libfribidi.so:converters/fribidi \
		libunibreak.so:textproc/libunibreak

USE_GITHUB=	yes
GH_ACCOUNT=	geometer
GH_PROJECT=	FBReader

.if defined(WITH_DEBUG)
STATUS=		debug
.else
STATUS=		release
.endif

USES=		compiler gmake iconv pkgconfig sqlite tar:tgz
USE_LDCONFIG=	yes

INSTALL_TARGET=	do_install

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	TARGET_ARCH=desktop TARGET_STATUS=${STATUS} \
		ROOTDIR=${WRKSRC} INSTALLDIR=${PREFIX} LIBDIR=${PREFIX}/lib \
		LD="${CXX}"
MAKE_ARGS+=	MAKE=${MAKE_CMD} LIBDIR=${PREFIX}/lib

OPTIONS_SINGLE=		GUI
OPTIONS_SINGLE_GUI=	GTK2 QT4
OPTIONS_DEFAULT=	QT4
OPTIONS_SUB=		yes

GTK2_USE=	gnome=gtk20
GTK2_MAKE_ENV=	UI_TYPE=gtk

QT4_USE=	qt4=gui,corelib,imageformats,network,moc_build
QT4_LDFLAGS=	-L${QT_LIBDIR}
QT4_MAKE_ENV=	UI_TYPE=qt4

post-patch:
	@${REINPLACE_CMD} -e '/^CC/d;/^LD/d;/QTINCLUDE/s,-I.*$$,-I${QT_INCDIR},' \
		${WRKSRC}/makefiles/arch/desktop.mk
	@${REINPLACE_CMD} -e 's,-O3,,;s,-ldl,${ICONV_LIB},' \
		${WRKSRC}/makefiles/config.mk ${WRKSRC}/zlibrary/core/Makefile
	@${REINPLACE_CMD} -e 's/-llinebreak/-lunibreak/g' ${WRKSRC}/zlibrary/text/Makefile
	@${REINPLACE_CMD} -e 's/-llinebreak/-lunibreak/g' ${WRKSRC}/makefiles/*.mk
	@${REINPLACE_CMD} -e 's,/usr,${PREFIX},' ${WRKSRC}/fbreader/desktop/Makefile
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} \
		-e 's,make ,gmake ,'

pre-configure:
# This cannot be done in post-patch because build dependencies are installed
# after patching and they can pull in libiconv which can affect CFLAGS in
# Mk/Uses/iconv.mk.
	@${REINPLACE_CMD} 's|^CFLAGS =.*$$|CFLAGS = ${CFLAGS}|' \
		${WRKSRC}/makefiles/arch/desktop.mk

.include <bsd.port.mk>
