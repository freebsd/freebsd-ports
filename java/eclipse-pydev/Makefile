# New ports collection makefile for:	eclipse-pydev
# Date created:		2007-11-16
# Whom:			Nicola Vitale	<nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pydev
PORTVERSION=	2.6.0
PORTREVISION=	1
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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJYTHON}
RUN_DEPENDS+=	jython:${PORTSDIR}/lang/jython
.endif

USE_PYTHON=	yes
USE_ZIP=	yes

DISTDATE=	2012062818

SUB_FILES=	pkg-install
SUB_LIST=	BUNDLES_INFO=${BUNDLES_INFO} DISTDATE=${DISTDATE} \
		PLUGINDIR=${PLUGINDIR} PORTVERSION=${PORTVERSION}

pre-install:
	@# ignore javashell.py file, because there is a syntax error
	@# see http://goo.gl/E4epH
	${PYTHON_CMD} -m compileall  -x javashell.py -f ${WRKSRC}/plugins
	${PYTHON_CMD} -O -m compileall -x javashell.py -f ${WRKSRC}

REVDOM=	python.pydev
PLUGINDIR=	../../share/eclipse/dropins/pydev/eclipse/plugins
BUNDLES_INFO=	${PREFIX}/lib/eclipse/configuration/org.eclipse.equinox.simpleconfigurator/bundles.info
COMPONENTS=	com com.analysis com.codecompletion com.debug com.fastparser com.refactoring \
		org org.ast org.core org.customizations org.debug org.django org.help org.jython org.parser org.red_core org.refactoring
post-install:
	@${ECHO_MSG} "===>   Updating ${BUNDLES_INFO}"
.for d in com org
.	for c in ${COMPONENTS:M${d}*}
		@${ECHO_CMD} "${d}.${REVDOM}${c:S,${d},,},${PORTVERSION}.${DISTDATE},${PLUGINDIR}/${d}.${REVDOM}${c:S,${d},,}_${PORTVERSION}.${DISTDATE}/,4,false" >> ${BUNDLES_INFO}
.	endfor
.endfor
	@(${SORT} ${BUNDLES_INFO} > ${BUNDLES_INFO}.sort) && \
	${MV} ${BUNDLES_INFO}.sort ${BUNDLES_INFO}
	${CAT} ${PKGMESSAGE}

add-plist-post:
	@${ECHO_CMD} "@exec ${MKDIR} %D/share/eclipse/dropins/${PORTNAME}/eclipse/plugins/com.python.pydev.codecompletion_${PORTVERSION}.${DISTDATE}/icons" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${SED} -i '' -E '/^((org)|(com))\.python\.pydev/d' %D/lib/eclipse/configuration/org.eclipse.equinox.simpleconfigurator/bundles.info" >> ${TMPPLIST}

.include "${PORTSDIR}/java/eclipse/Makefile.plugins"

.include <bsd.port.mk>
