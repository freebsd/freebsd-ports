# $FreeBSD$

PORTNAME=	gworkspace
PORTVERSION=	0.9.4
PORTREVISION=	3
CATEGORIES=	deskutils gnustep
#MASTER_SITES=	http://www.gnustep.it/enrico/gworkspace/
MASTER_SITES=	GNUSTEP/usr-apps

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNUstep workspace manager

LICENSE=	GPLv2

USES=		gnustep
USE_GNUSTEP=	back build
USE_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

GNU_CONFIGURE=	yes
ADDITIONAL_LDFLAGS+=	-L${WRKSRC}/FSNode/FSNode.framework/Versions/A

.if defined(WITHOUT_GHOSTSCRIPT)
PLIST_SUB+=	PDFVIEW="@comment "
.else
PLIST_SUB+=	PDFVIEW=""
USES+=		ghostscript
.endif

post-patch:
# Fix the build with -fno-common (for Clang 11 and GCC 10)
	@${REINPLACE_CMD} -e '/serverConnection/s,^,extern ,' \
		${WRKSRC}/Inspector/ContentViewers/ImageViewer/Resizer.h

pre-configure:
	${RM} -r ${WRKSRC}/GWMetadata

.include <bsd.port.mk>
