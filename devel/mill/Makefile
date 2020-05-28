# $FreeBSD$

PORTNAME=	mill
DISTVERSION=	0.7.3
CATEGORIES=	devel java
MASTER_SITES=	https://github.com/lihaoyi/mill/releases/download/${PORTVERSION}/
DISTNAME=	${PORTVERSION}-assembly
EXTRACT_SUFX=
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=

MAINTAINER=	freebsd-ports@jan0sch.de
COMMENT=	Java/Scala build tool

LICENSE=	MIT

USE_JAVA=	yes
JAVA_VERSION=	1.8+

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
