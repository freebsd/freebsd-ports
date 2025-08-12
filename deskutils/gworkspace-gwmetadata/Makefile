PORTNAME=	gworkspace
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	deskutils gnustep
MASTER_SITES=	GNUSTEP/usr-apps
PKGNAMESUFFIX=	-gwmetadata${PKGNAMESUFFIX2}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GWMetadata for GNUstep workspace manager
WWW=		http://www.gnustep.it/enrico/gworkspace/

LICENSE=	GPLv2

USES=		gnustep sqlite
USE_GNUSTEP=	back build
GNU_CONFIGURE=	yes
LIB_DEPENDS=	libDBKit.so:deskutils/gworkspace \
		libPreferencePanes.so:deskutils/systempreferences
USE_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

LDFLAGS+=	-lpthread

WRKSRC=		${WRKDIR}/gworkspace-${PORTVERSION}/GWMetadata
CONFIGURE_ARGS+=	--with-sqlite-include=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-sqlite-library=${LOCALBASE}/lib
DEFAULT_LIBVERSION=	0.1.0

post-patch:
	${CP} ${FILESDIR}/Preferences-GNUmakefile \
		${WRKSRC}/Preferences/GNUmakefile
	${CP} ${FILESDIR}/MDFinder-GNUmakefile \
		${WRKSRC}/MDFinder/GNUmakefile

.include <bsd.port.mk>
