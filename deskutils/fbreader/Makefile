# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fbreader
PORTVERSION=	0.99.4
DISTVERSIONPREFIX=	sources-
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	http://www.fbreader.org/files/desktop/ \
		http://old.fbreader.org/

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Powerful e-book reader

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libfribidi.so:${PORTSDIR}/converters/fribidi \
		libunibreak.so:${PORTSDIR}/textproc/libunibreak

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

USES=		iconv gmake pkgconfig tar:tgz
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
MAKE_ARGS+=	MAKE=${MAKE_CMD} LIBDIR=${PREFIX}/lib

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS/s,-pipe.*$$,${CFLAGS} -DDO_ICONV_CAST -DLIBICONV_PLUG,' \
		-e '/^CC/d;/^LD/d;/QTINCLUDE/s,-I.*$$,-I${QT_INCDIR},;s,libpng ,libpng15 ,' \
		${WRKSRC}/makefiles/arch/desktop.mk
	@${REINPLACE_CMD} -e 's,-O3,,;s,-ldl,${ICONV_LIB},' \
		${WRKSRC}/makefiles/config.mk ${WRKSRC}/zlibrary/core/Makefile
	@${REINPLACE_CMD} -e 's,/usr,${PREFIX},' ${WRKSRC}/fbreader/desktop/Makefile
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} \
		-e 's,make ,gmake ,'

.include <bsd.port.mk>
