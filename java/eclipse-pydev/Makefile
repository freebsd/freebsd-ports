# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pydev
PORTVERSION=	2.8.1
PORTREVISION=	0
CATEGORIES=	java devel python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/PyDev%20${PORTVERSION}/
PKGNAMEPREFIX=	eclipse-
DISTNAME=	PyDev%20${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Eclipse plugin for Python and Jython development

LICENSE=	EPL

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse

NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=	JYTHON
JYTHON_DESC=	Use Jython as Python interpreter

USES=		zip

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJYTHON}
RUN_DEPENDS+=	jython:${PORTSDIR}/lang/jython
.endif

USE_PYTHON=	yes

DISTDATE=	2013072611

SUB_FILES=	pkg-install
SUB_LIST=	BUNDLES_INFO=${BUNDLES_INFO} PLUGINDIR=${PLUGINDIR}

pre-install:
	@# ignore javashell.py file, because there is a syntax error
	@# see http://goo.gl/E4epH
	${PYTHON_CMD} -m compileall  -x javashell.py -f ${WRKSRC}/plugins
	${PYTHON_CMD} -O -m compileall -x javashell.py -f ${WRKSRC}

PLUGINDIR=	share/eclipse/dropins/pydev/eclipse/plugins
BUNDLES_INFO=	${PREFIX}/lib/eclipse/configuration/org.eclipse.equinox.simpleconfigurator/bundles.info

post-install:
	@${ECHO_MSG} "===>   Updating ${BUNDLES_INFO}"
	@PLUGINS=$$(ls -1 ${PREFIX}/${PLUGINDIR}); \
	for d in $${PLUGINS}; do \
	    (${ECHO_CMD} "$${d},../../${PLUGINDIR}/$${d}/,4,false" | \
	    ${SED} -e 's/_\([0-9]\)/,\1/1' -e '/templates/d') >> ${BUNDLES_INFO}; \
	done
	@(${SORT} ${BUNDLES_INFO} > ${BUNDLES_INFO}.sort) && \
	${MV} ${BUNDLES_INFO}.sort ${BUNDLES_INFO}
	@${CAT} ${PKGMESSAGE}

add-plist-post:
	@${ECHO_CMD} "@exec ${MKDIR} %D/share/eclipse/dropins/${PORTNAME}/eclipse/plugins/com.python.pydev.codecompletion_${PORTVERSION}.${DISTDATE}/icons" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${SED} -i '' -E '/^((org)|(com))\.python\.pydev/d' %D/lib/eclipse/configuration/org.eclipse.equinox.simpleconfigurator/bundles.info" >> ${TMPPLIST}

.include "${PORTSDIR}/java/eclipse/Makefile.plugins"

.include <bsd.port.mk>
