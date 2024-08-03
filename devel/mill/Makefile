PORTNAME=	mill
DISTVERSION=	0.11.10
CATEGORIES=	devel java
MASTER_SITES=	https://github.com/lihaoyi/${PORTNAME}/releases/download/${DISTVERSION}/
DISTNAME=	${DISTVERSION}-assembly
EXTRACT_SUFX=
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=

MAINTAINER=	freebsd-ports@jan0sch.de
COMMENT=	Java/Scala build tool
WWW=		https://www.lihaoyi.com/mill/

LICENSE=	MIT

USE_JAVA=	yes
JAVA_VERSION=	8+

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/mill

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
