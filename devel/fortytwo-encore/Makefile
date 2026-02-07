PORTNAME=	encore
PORTVERSION=	0.3.1
PORTREVISION=	11
CATEGORIES=	devel gnustep
MASTER_SITES=	SF/fortytwo/Encore/${PORTVERSION}
PKGNAMEPREFIX=	fortytwo-
DISTFILES=	Encore-${PORTVERSION}-src.tgz \
		Encore-${PORTVERSION}-api-ref.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility classes for GNUstep
WWW=		https://fortytwo.sourceforge.net/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gnustep
USE_GNUSTEP=	back build
DEFAULT_LIBVERSION=	0.1
USE_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

WRKSRC=		${WRKDIR}/Encore
DOCSDIR=	${GNUSTEP_PREFIX}/Local/Library/Documentation/Encore

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Library/Frameworks/Encore.framework/Versions/0/libEncore.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKDIR}/Encore-${PORTVERSION}-api-ref && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
