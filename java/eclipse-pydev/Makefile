# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pydev
PORTVERSION=	3.5.0
PORTREVISION=	2
CATEGORIES=	java devel python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/PyDev%20${PORTVERSION}/
PKGNAMEPREFIX=	eclipse-
DISTNAME=	PyDev%20${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Eclipse plugin for Python and Jython development

LICENSE=	EPL

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:java/eclipse

BUNDLES_INFO=	${PREFIX}/share/eclipse/configuration/org.eclipse.equinox.simpleconfigurator/bundles.info

JYTHON_DESC=	Use Jython as Python interpreter

NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=	JYTHON

PLUGINDIR=	share/eclipse/dropins/pydev/eclipse/plugins
PYDEV_BUNDLES_INFO=	${PREFIX}/${PLUGINDIR}/bundles.info

USES=		python:2.7 zip

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJYTHON}
RUN_DEPENDS+=	jython:lang/jython
.endif

pre-install:
	@${ECHO_MSG} "===>   Creating bundles.info"
	@PLUGINS=$$(ls -1 ${WRKSRC}/plugins); \
	for d in $${PLUGINS}; do \
	    (${ECHO_CMD} "$${d},../../${PLUGINDIR}/$${d}/,4,false" | \
	    ${SED} -e 's/_\([0-9]\)/,\1/1' -e '/templates/d') >> ${WRKSRC}/plugins/bundles.info; \
	done
	@# ignore javashell.py file, because there is a syntax error
	@# see http://goo.gl/E4epH
	${PYTHON_CMD} -m compileall -x javashell.py -f ${WRKSRC}/plugins
	${PYTHON_CMD} -O -m compileall -x javashell.py -f ${WRKSRC}

add-plist-post:
	${ECHO_CMD} "@exec ${CAT} ${PYDEV_BUNDLES_INFO} >> ${BUNDLES_INFO}" >> ${TMPPLIST}
	${ECHO_CMD} "@unexec ${SED} -i '' -E '/^((org)|(com))\.python\.pydev/d' %D/share/eclipse/configuration/org.eclipse.equinox.simpleconfigurator/bundles.info" >> ${TMPPLIST}

.include "${PORTSDIR}/java/eclipse/Makefile.plugins"

.include <bsd.port.mk>
