PORTNAME=	coursier
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.9
CATEGORIES=	devel java
MASTER_SITES=	https://github.com/coursier/coursier/releases/download/${DISTVERSIONFULL}/
DISTNAME= ${PORTNAME}
EXTRACT_SUFX=
DIST_SUBDIR= ${PORTNAME}/${DISTVERSION}

MAINTAINER=	freebsd-ports@jan0sch.de
COMMENT=	Pure Scala Artifact Fetching
WWW=		https://get-coursier.io/

LICENSE=	APACHE20

USE_JAVA=	yes
JAVA_VERSION=	8+

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/coursier

do-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${WRKDIR}

post-patch:
	${REINPLACE_CMD} -e 's,JAVA_CMD=java,JAVA_CMD=${JAVA},' ${WRKDIR}/${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
