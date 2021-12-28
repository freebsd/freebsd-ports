# Created by: Craig Leres <leres@FreeBSD.org>

PORTNAME=	arduino-irremote
PORTVERSION=	3.5.2
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	leres@FreeBSD.org
COMMENT=	Multi-protocol infrared remote library for the Arduino

LICENSE=	MIT

USES=		dos2unix
USE_GITHUB=	yes
GH_ACCOUNT=	z3t0
GH_PROJECT=	Arduino-IRremote

NO_BUILD=	yes

RELPATH=	arduino/libraries/IRremote

DATADIR=	${PREFIX}/${RELPATH}
PORTDATA=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${RELPATH}
	cd ${WRKSRC}/src && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${RELPATH}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
