# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fbreader
PORTVERSION=	0.99.6
DISTVERSIONSUFFIX=	-freebsdport
PORTREVISION=	4
CATEGORIES=	deskutils

MAINTAINER=	johannes@perceivon.net
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

USES=		compiler gmake gnome iconv localbase pkgconfig sqlite
USE_GNOME=	gtk20
USE_LDCONFIG=	yes

INSTALL_TARGET=	do_install

MAKE_ENV+=	TARGET_ARCH=desktop TARGET_STATUS=${STATUS} \
		ROOTDIR=${WRKSRC} INSTALLDIR=${PREFIX} LIBDIR=${PREFIX}/lib \
		LD="${CXX}" UI_TYPE=gtk
MAKE_ARGS+=	MAKE=${MAKE_CMD} LIBDIR=${PREFIX}/lib

post-patch:
	@${REINPLACE_CMD} -e '/^CC/d;/^LD/d;/QTINCLUDE/s,-I.*$$,-I${QT_INCDIR},' \
		${WRKSRC}/makefiles/arch/desktop.mk
	@${REINPLACE_CMD} -e 's,-O3,,;s,-ldl,${ICONV_LIB},' \
		${WRKSRC}/makefiles/config.mk ${WRKSRC}/zlibrary/core/Makefile
	@${REINPLACE_CMD} -e 's/-llinebreak/-lunibreak/g' ${WRKSRC}/zlibrary/text/Makefile
	@${REINPLACE_CMD} -e 's/-llinebreak/-lunibreak/g' ${WRKSRC}/makefiles/*.mk
	@${REINPLACE_CMD} -e 's,/usr,${PREFIX},' ${WRKSRC}/fbreader/desktop/Makefile
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} \
		-e 's,make ,$$(MAKE) ,' -e '/$$(LDFLAGS)/s/$$/ $$(LIBS)/'

pre-configure:
# This cannot be done in post-patch because build dependencies are installed
# after patching and they can pull in libiconv which can affect CFLAGS in
# Mk/Uses/iconv.mk.
	@${REINPLACE_CMD} 's|^CFLAGS =.*$$|CFLAGS = ${CFLAGS}|' \
		${WRKSRC}/makefiles/arch/desktop.mk

.include <bsd.port.mk>
