# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
# $FreeBSD$

PORTNAME=	weather
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	astro python
MASTER_SITES=	http://fungi.yuggoth.org/weather/src/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utility to provide current weather conditions and forecasts

LICENSE=	ISCL

CONFLICTS_INSTALL=	expect-[0-9]* expect-nox11-[0-9]*

USE_PYTHON=	yes
USE_XZ=		yes
USES=		shebangfix

MAN1=		${PORTNAME}.1
MAN5=		${PORTNAME}rc.5
PLIST_FILES=	bin/${PORTNAME} \
		%%PYTHON_SITELIBDIR%%/${PORTNAME}.py \
		%%PYTHON_SITELIBDIR%%/${PORTNAME}.pyc \
		%%PYTHON_SITELIBDIR%%/${PORTNAME}.pyo
PORTDATA=	airports places stations zctas zones

SHEBANG_FILES=	${PORTNAME}
python_OLD_CMD=	${SETENV} python
python_CMD=	${PYTHON_CMD}

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}/${PORTNAME}.py
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}/${PORTNAME}.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTNAME}.py ${PORTNAME}.pyc ${PORTNAME}.pyo ${PYTHON_SITELIBDIR}/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1/${PORTNAME}.1
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}rc.5 ${MANPREFIX}/man/man5/${PORTNAME}rc.5
	${MKDIR} ${DATADIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDATA} ${DATADIR}/

post-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Please add the following to your .weatherrc in order to use installed data files:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "[default]"
	@${ECHO_MSG} "setpath = ${DATADIR}"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
