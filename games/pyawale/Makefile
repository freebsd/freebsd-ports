# New ports collection makefile for:	pyawale
# Date created:		14 August 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pyawale
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://download.gna.org/pyawale/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	African board game

LICENSE=	GPLv2

RUN_DEPENDS=	py*-game>=1.7.1:${PORTSDIR}/devel/py-game

USE_PYTHON=	yes

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/src
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/src
	@${ECHO_CMD} "#!/bin/sh" > ${WRKSRC}/${PORTNAME}
	@${ECHO_CMD} "exec ${PYTHON_CMD} \
		${PYTHONPREFIX_SITELIBDIR}/pyAwale/${PORTNAME}.py" \
		>> ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${PYTHONPREFIX_SITELIBDIR}/pyAwale
	@(cd ${WRKSRC}/src \
		&& ${COPYTREE_SHARE} . ${PYTHONPREFIX_SITELIBDIR}/pyAwale)
	@${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/docs/${PORTNAME}.desktop \
		${PREFIX}/share/applications
	@${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/docs/${PORTNAME}.png \
		${PREFIX}/share/pixmaps
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in AUTHORS ChangeLog NEWS README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	@${MKDIR} ${DOCSDIR}/docs
	${INSTALL_DATA} ${WRKSRC}/docs/*.jpg ${DOCSDIR}/docs
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${DOCSDIR}/docs
	${INSTALL_DATA} ${WRKSRC}/docs/*.rest ${DOCSDIR}/docs
.endif

.include <bsd.port.mk>
