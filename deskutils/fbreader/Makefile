# New ports collection makefile for:	fbreader
# Date created:		29 March 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fbreader
PORTVERSION=	0.12.10
PORTREVISION=	3
DISTVERSIONPREFIX=	sources-
CATEGORIES=	deskutils
MASTER_SITES=	http://www.fbreader.org/files/sources/ \
		http://old.fbreader.org/
EXTRACT_SUFX=	.tgz

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Powerful e-book reader

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		expat.6:${PORTSDIR}/textproc/expat2 \
		fribidi.3:${PORTSDIR}/converters/fribidi \
		linebreak.2:${PORTSDIR}/textproc/liblinebreak

.if defined(WITH_GTK2)
UI=		gtk
USE_GNOME=	gtk20
.else
UI=		qt4
USE_QT4=	gui corelib imageformats network moc_build
LDFLAGS+=	-L${QT_LIBDIR}
.endif

.if defined(WITH_DEBUG)
STATUS=		debug
.else
STATUS=		release
.endif

USE_GMAKE=	yes
USE_SQLITE=	yes
USE_LDCONFIG=	yes

INSTALL_TARGET=	do_install
PLIST_SUB=	UI=${UI}
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	TARGET_ARCH=desktop UI_TYPE=${UI} TARGET_STATUS=${STATUS} \
		ROOTDIR=${WRKSRC} INSTALLDIR=${PREFIX} LIBDIR=${PREFIX}/lib \
		LD="${CXX}"
MAKE_ARGS+=	MAKE=${GMAKE} LIBDIR=${PREFIX}/lib

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS/s,-pipe.*$$,${CFLAGS} -DDO_ICONV_CAST -DLIBICONV_PLUG,' \
		-e '/^CC/d;/^LD/d;/QTINCLUDE/s,-I.*$$,-I${QT_INCDIR},;s,libpng ,libpng15 ,' \
		${WRKSRC}/makefiles/arch/desktop.mk
	@${REINPLACE_CMD} -e 's,-O3,,;s,-ldl,-liconv,' \
		${WRKSRC}/makefiles/config.mk ${WRKSRC}/zlibrary/core/Makefile
	@${REINPLACE_CMD} -e 's,/usr,${PREFIX},' ${WRKSRC}/fbreader/desktop/Makefile
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} \
		-e 's,make ,gmake ,'

.include <bsd.port.mk>
