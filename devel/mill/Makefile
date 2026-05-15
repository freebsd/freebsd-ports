PORTNAME=	mill
DISTVERSION=	0.12.5
CATEGORIES=	devel java
MASTER_SITES=	https://github.com/com-lihaoyi/${PORTNAME}/releases/download/${DISTVERSION}/
DISTNAME=	${DISTVERSION}-assembly
EXTRACT_SUFX=
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	freebsd-ports@jan0sch.de
COMMENT=	Java/Scala build tool
WWW=		https://mill-build.org/

LICENSE=	MIT

USES=		java

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	.
NO_ARCH=	yes
NO_BUILD=	yes

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/mill

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
