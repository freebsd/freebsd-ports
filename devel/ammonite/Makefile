PORTNAME=	ammonite
DISTVERSION=	3.0.8
CATEGORIES=	devel java
MASTER_SITES=	https://github.com/lihaoyi/Ammonite/releases/download/${DISTVERSION}/
DISTNAME=	3.3-${DISTVERSION}
EXTRACT_SUFX=
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	freebsd-ports@jan0sch.de
COMMENT=	Provides a system shell in the high-level Scala language
WWW=		https://ammonite.io/

LICENSE=	MIT

USES=		java

EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=	#
EXTRACT_AFTER_ARGS=	${WRKSRC}

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/ammonite

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
