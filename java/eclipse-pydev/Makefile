PORTNAME=	pydev
PORTVERSION=	12.0.0
PORTREVISION=	1
CATEGORIES=	java devel python
MASTER_SITES=	https://github.com/fabioz/Pydev/releases/download/${PORTNAME}_12_0_0/
PKGNAMEPREFIX=	eclipse-
DISTNAME=	PyDev.${PORTVERSION}

MAINTAINER=	mizhka@FreeBSD.org
COMMENT=	Eclipse plugin for Python and Jython development
WWW=		https://www.pydev.org/

LICENSE=	EPL

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:java/eclipse

USES=		java python zip
JAVA_OS=	native

NO_BUILD=	YES
NO_WRKSUBDIR=	YES

PLIST_SUB+=     PYDEV_VER=12.0.0.202402010911

OPTIONS_DEFINE=	JYTHON

JYTHON_DESC=	Use Jython as Python interpreter

JYTHON_RUN_DEPENDS=	jython:lang/jython

PLUGINDIR=	share/eclipse/dropins/${PORTNAME}/eclipse

do-install:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "features plugins" ${STAGEDIR}${PREFIX}/${PLUGINDIR})

.include <bsd.port.mk>
