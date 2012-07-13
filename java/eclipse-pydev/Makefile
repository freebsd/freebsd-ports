# New ports collection makefile for:	eclipse-pydev
# Date created:		2007-11-16
# Whom:			Nicola Vitale	<nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pydev
PORTVERSION=	2.6.0
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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJYTHON}
RUN_DEPENDS+=	jython:${PORTSDIR}/lang/jython
.endif

PLIST_SUB=	PORTVERSION=${PORTVERSION}.${DISTDATE}

USE_PYTHON=	yes
USE_ZIP=	yes

DISTDATE=	2012062818

pre-install:
	@# ignore javashell.py file, because there is a syntax error
	@# see http://goo.gl/E4epH
	${PYTHON_CMD} -m compileall  -x javashell.py -f ${WRKSRC}/plugins
	${PYTHON_CMD} -O -m compileall -x javashell.py -f ${WRKSRC}

post-install:
	@# Update the bundles.info...
	@${LOCALBASE}/bin/eclipse -consoleLog -initialize
	@${CAT} ${PKGMESSAGE}

add-plist-post:
	@${ECHO_CMD} "@exec ${MKDIR} %D/share/eclipse/dropins/${PORTNAME}/eclipse/plugins/com.python.pydev.codecompletion_${PORTVERSION}.${DISTDATE}/icons" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${LOCALBASE}/bin/eclipse -consoleLog -initialize" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${LOCALBASE}/bin/eclipse -consoleLog -initialize" >> ${TMPPLIST}

.include "${PORTSDIR}/java/eclipse/Makefile.plugins"

.include <bsd.port.mk>
