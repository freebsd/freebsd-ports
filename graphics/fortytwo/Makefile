# $FreeBSD$

PORTNAME=	fortytwo
PORTVERSION=	0.2.0
PORTREVISION=	8
CATEGORIES=	graphics gnustep
MASTER_SITES=	SF/${PORTNAME}/FT%20%2842%29/${PORTVERSION}
DISTFILES=	FT-${PORTVERSION}-src.tgz \
		FT-${PORTVERSION}-api-ref.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graph management system for GNUstep

LICENSE=	LGPL21

USES=		bdb gnustep
USE_GNUSTEP=	back build

LIB_DEPENDS=	libEncore.so:devel/fortytwo-encore \
		libBDB.so:databases/fortytwo-bdb
DEFAULT_LIBVERSION=	0.1
USE_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

WRKSRC=		${WRKDIR}/FT-${PORTVERSION}
DOCSDIR=	${GNUSTEP_PREFIX}/Local/Library/Documentation/FT

ADDITIONAL_OBJCFLAGS+=	-I${BDB_INCLUDE_DIR}
ADDITIONAL_LDFLAGS+=	-L${BDB_LIB_DIR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Library/Frameworks/FT.framework/Versions/0/libFT.so

.include <bsd.port.mk>
