# Ports collection makefile for: LibChipCard
# Date created:                  19 January 2003
# Whom:                          Martin Preuss <martin@libchipcard.de>
#
# $FreeBSD$
#

PORTNAME=	libchipcard
DISTVERSION=	5.0.1test
CATEGORIES=	devel
MASTER_SITES=	http://www.aquamaniac.de/sites/download/download.php?package=02&release=25&file=01&dummy=

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	A library for easy access to chipcards

LIB_DEPENDS=	pcsclite.1:${PORTSDIR}/devel/pcsc-lite \
		gwenhywfar.60:${PORTSDIR}/devel/gwenhywfar

FETCH_ARGS+=	-o ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV+=	PTHREAD_LIBS="${PTHREAD_LIBS}" aq_distrib_name="FreeBSD"
CONFIGURE_ARGS+=--with-pcsc-includes=${LOCALBASE}/include \
			--with-pcsc-libs=${LOCALBASE}/lib
PLIST_SUB=	GWEN_PLUGINS="${GWEN_PLUGINS}"
USE_LDCONFIG=	yes

GWEN_SHLIB_VER=	60
GWEN_PLUGINS=	${LOCALBASE}/lib/gwenhywfar/plugins/${GWEN_SHLIB_VER}

post-patch:
	${REINPLACE_CMD} -e 's|aq_endian\" ==|aq_endian\" =|g' \
		${WRKSRC}/configure

post-install:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},' ${PKGMESSAGE}

.include <bsd.port.mk>
