# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
# $FreeBSD$

PORTNAME=	weather
PORTVERSION=	2.3
CATEGORIES=	astro python
MASTER_SITES=	http://fungi.yuggoth.org/weather/src/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utility to provide current weather conditions and forecasts

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python shebangfix tar:xz

PLIST_FILES=	bin/${PORTNAME} \
		%%PYTHON_SITELIBDIR%%/${PORTNAME}.py \
		%%PYTHON_SITELIBDIR%%/${PYCACHE_DIR}${PYCACHE_FILE}.pyc \
		%%PYTHON_SITELIBDIR%%/${PYCACHE_DIR}${PYCACHE_FILE}.${PYTHON_PYOEXTENSION} \
		man/man1/${PORTNAME}.1.gz \
		man/man5/${PORTNAME}rc.5.gz
PORTDATA=	airports places stations zctas zones

SHEBANG_FILES=	${PORTNAME}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3200
PYCACHE_DIR=	# empty
PYCACHE_FILE=	${PORTNAME}
.else
PYCACHE_DIR=	__pycache__/
PYCACHE_FILE=	${PORTNAME}.cpython-${PYTHON_SUFFIX}
.endif

.if ${PYTHON_REL} < 3500
PYTHON_PYOEXTENSION=	pyo
.else
PYTHON_PYOEXTENSION=	opt-1.pyc
.endif

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}/${PORTNAME}.py
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}/${PORTNAME}.py

do-install:
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/ ${STAGEDIR}${PYTHON_SITELIBDIR}/${PYCACHE_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.py ${STAGEDIR}${PYTHON_SITELIBDIR}/
	${INSTALL_DATA} ${WRKSRC}/${PYCACHE_DIR}${PYCACHE_FILE}.pyc ${STAGEDIR}${PYTHON_SITELIBDIR}/${PYCACHE_DIR}
	${INSTALL_DATA} ${WRKSRC}/${PYCACHE_DIR}${PYCACHE_FILE}.${PYTHON_PYOEXTENSION} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PYCACHE_DIR}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1/${PORTNAME}.1
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}rc.5 ${STAGEDIR}${MANPREFIX}/man/man5/${PORTNAME}rc.5
	${MKDIR} ${STAGEDIR}${DATADIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDATA} ${STAGEDIR}${DATADIR}/
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Please add the following to your .weatherrc in order to use installed data files:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "[default]"
	@${ECHO_MSG} "setpath = ${DATADIR}"
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
