# $FreeBSD$

PORTNAME=	bdb
PORTVERSION=	0.2.1
PORTREVISION=	8
CATEGORIES=	databases gnustep
MASTER_SITES=	SF/fortytwo/Berkeley%20DB%20Wrapper%20%28BDB%29/${PORTVERSION}
PKGNAMEPREFIX=	fortytwo-
DISTFILES=	BDB-${PORTVERSION}-src.tgz \
		BDB-${PORTVERSION}-api-ref.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interface to Berkeley DB for GNUstep

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		bdb gnustep
USE_GNUSTEP=	back build

LIB_DEPENDS=	libEncore.so:devel/fortytwo-encore
DEFAULT_LIBVERSION=	0.1
USE_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

WRKSRC=		${WRKDIR}/BDB-${PORTVERSION}
DOCSDIR=	${GNUSTEP_PREFIX}/Local/Library/Documentation/BDB
ADDITIONAL_OBJCFLAGS+=	-I${BDB_INCLUDE_DIR} -I${GNUSTEP_PREFIX}/
ADDITIONAL_LDFLAGS+=	-L${BDB_LIB_DIR}

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Library/Frameworks/BDB.framework/Versions/0/libBDB.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKDIR}/BDB-0.2.0-api-ref && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
