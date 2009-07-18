# New ports collection makefile for:	pikdev
# Date created:		2006-03-14
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	pikdev
PORTVERSION=	0.9.2
PORTREVISION=	4
CATEGORIES=	devel kde
MASTER_SITES=	http://pikdev.free.fr/
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Simple graphic IDE for the development of PIC-based applications

LIB_DEPENDS=	fam.0:${PORTSDIR}/devel/gamin \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.10:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	gpasm:${PORTSDIR}/devel/gputils

USE_KDEBASE_VER=3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
INSTALLS_ICONS=	yes
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}" CFLAGS="${CFLAGS}"
CONFIGURE_ARGS+=	--with-pic=yes
MAKE_ENV=	LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"
SUB_FILES=	pkg-message

OPTIONS=	DEBUG	"Enable debug information"	off \
		NLS	"Native Language Support"	on

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug=full
.endif

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
FLAG_NLS=	true
.endif

post-patch:
	${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|-Wmissing-prototypes||g' ${WRKSRC}/configure

post-configure:
	${REINPLACE_CMD} -e 's|^install-data-am: install-docs install-nls|install-data-am:|g' \
		${WRKSRC}/doc/en/${MAKEFILE}
.if !defined(FLAG_NLS)
	${REINPLACE_CMD} -e 's|^install-data-am: install-nls|install-data-am:|g' ${WRKSRC}/po/Makefile
.endif

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
