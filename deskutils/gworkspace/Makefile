# $FreeBSD$

PORTNAME=	gworkspace
PORTVERSION=	0.9.3
CATEGORIES=	deskutils gnustep
#MASTER_SITES=	http://www.gnustep.it/enrico/gworkspace/
MASTER_SITES=	GNUSTEP/usr-apps

MAINTAINER=	theraven@FreeBSD.org
COMMENT=	GNUstep workspace manager

LICENSE=	GPLv2

USES=		gnustep
USE_GNUSTEP=	back build
USE_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

GNU_CONFIGURE=	yes
ADDITIONAL_LDFLAGS+=	-L${WRKSRC}/FSNode/FSNode.framework/Versions/A
MAKE_ENV+=	GNUSTEP_INSTALLATION_DOMAIN=SYSTEM

.if defined(WITHOUT_GHOSTSCRIPT)
PLIST_SUB+=	PDFVIEW="@comment "
.else
PLIST_SUB+=	PDFVIEW=""
USE_GHOSTSCRIPT=	yes
.endif

pre-configure:
	${RM} -rf ${WRKSRC}/GWMetadata

.include <bsd.port.mk>
