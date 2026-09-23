PORTNAME=	cfr
DISTVERSION=	0.152
PORTREVISION=	2
CATEGORIES=	devel java
MASTER_SITES=	http://www.benf.org/other/cfr/ \
		https://www.benf.org/other/cfr/ \
		https://github.com/leibnitz27/cfr/releases/download/${DISTVERSION}/
DISTFILES=	${_JARDISTFILE} \
		license.html
DIST_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Class File Reader (CFR) Java decompiler
WWW=		https://www.benf.org/other/cfr/

LICENSE=	MIT
LICENSE_FILE=	${WRKDIR}/license.html

USES=		java

NO_ARCH=	yes
NO_BUILD=	yes
PLIST_FILES=	${JAVAJARDIR}/cfr.jar

_JARDISTFILE=	${PORTNAME}-${DISTVERSIONFULL}${EXTRACT_SUFX}
_JARFILE=	${PORTNAME}.jar

post-extract:
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/license.html ${WRKDIR}

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${_JARDISTFILE} \
		${STAGEDIR}${JAVAJARDIR}/${_JARFILE}

do-test:
# Find out if the decompiler works.
	${JAVA} -jar ${STAGEDIR}${JAVAJARDIR}/${_JARFILE} \
		${STAGEDIR}${JAVAJARDIR}/${_JARFILE} >/dev/null

.include <bsd.port.mk>
