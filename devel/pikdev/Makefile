# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	pikdev
PORTVERSION=	0.9.2
PORTREVISION=	9
CATEGORIES=	devel kde
MASTER_SITES=	http://pikdev.free.fr/
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Simple graphic IDE for the development of PIC-based applications

LIB_DEPENDS=	fam.0:${PORTSDIR}/devel/gamin \
		png15:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	gpasm:${PORTSDIR}/devel/gputils

USE_KDEBASE_VER=3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
LDFLAGS+=	-L${LOCALBASE}/lib -pthread
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-pic=yes
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DEBUG NLS

.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug=full
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=	gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|-Wmissing-prototypes||g' ${WRKSRC}/configure

post-configure:
	${REINPLACE_CMD} -e 's|^install-data-am: install-docs install-nls|install-data-am:|g' \
		${WRKSRC}/doc/en/${MAKEFILE}
.if ! ${PORT_OPTIONS:MNLS}
	${REINPLACE_CMD} -e 's|^install-data-am: install-nls|install-data-am:|g' ${WRKSRC}/po/Makefile
.endif

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
