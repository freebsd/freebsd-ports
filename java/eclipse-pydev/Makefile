# Created by: Nicola Vitale <nivit@FreeBSD.org>

PORTNAME=	pydev
PORTVERSION=	8.2.0
CATEGORIES=	java devel python
MASTER_SITES= https://github.com/fabioz/Pydev/releases/download/${PORTNAME}_8_2_0/
PKGNAMEPREFIX=	eclipse-
DISTNAME=	PyDev.${PORTVERSION}

MAINTAINER=	mizhka@FreeBSD.org
COMMENT=	Eclipse plugin for Python and Jython development

LICENSE=	EPL

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:java/eclipse

USES=		python zip

JYTHON_DESC=	Use Jython as Python interpreter
OPTIONS_DEFINE=	JYTHON

USE_JAVA=	YES
JAVA_OS=	native
JAVA_RUN=	YES
JAVA_VERSION=	1.8+

NO_BUILD=	YES
NO_WRKSUBDIR=	YES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJYTHON}
RUN_DEPENDS+=	jython:lang/jython
.endif

PLUGINDIR=	share/eclipse/dropins/${PORTNAME}/eclipse

do-install:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "features plugins" ${STAGEDIR}${PREFIX}/${PLUGINDIR})

.include <bsd.port.mk>
