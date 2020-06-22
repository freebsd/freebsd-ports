# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
# $FreeBSD$

PORTNAME=	weather
PORTVERSION=	2.4
CATEGORIES=	astro python
MASTER_SITES=	http://fungi.yuggoth.org/weather/src/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utility to provide current weather conditions and forecasts

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python shebangfix tar:xz

NO_ARCH=	yes

PLIST_FILES=	bin/weather \
		${PYTHON_SITELIBDIR}/weather.py \
		${PYTHON_SITELIBDIR}/${PYCACHE_DIR}${PYCACHE_FILE}.pyc \
		${PYTHON_SITELIBDIR}/${PYCACHE_DIR}${PYCACHE_FILE}.${PYTHON_PYOEXTENSION} \
		share/man/man1/weather.1.gz \
		share/man/man5/weatherrc.5.gz
PORTDATA=	airports places stations zctas zones

SHEBANG_FILES=	weather

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3200
PYCACHE_DIR=	# none
PYCACHE_FILE=	weather
.else
PYCACHE_DIR=	__pycache__/
PYCACHE_FILE=	weather.cpython-${PYTHON_SUFFIX}
.endif

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}/weather.py
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}/weather.py

do-install:
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/ ${STAGEDIR}${PYTHON_SITELIBDIR}/${PYCACHE_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/weather ${STAGEDIR}${PREFIX}/bin/weather
	${INSTALL_DATA} ${WRKSRC}/weather.py ${STAGEDIR}${PYTHON_SITELIBDIR}/
	${INSTALL_DATA} ${WRKSRC}/${PYCACHE_DIR}${PYCACHE_FILE}.pyc ${STAGEDIR}${PYTHON_SITELIBDIR}/${PYCACHE_DIR}
	${INSTALL_DATA} ${WRKSRC}/${PYCACHE_DIR}${PYCACHE_FILE}.${PYTHON_PYOEXTENSION} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PYCACHE_DIR}
	${INSTALL_MAN} ${WRKSRC}/weather.1 ${STAGEDIR}${PREFIX}/share/man/man1/weather.1
	${INSTALL_MAN} ${WRKSRC}/weatherrc.5 ${STAGEDIR}${PREFIX}/share/man/man5/weatherrc.5
	${MKDIR} ${STAGEDIR}${DATADIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDATA} ${STAGEDIR}${DATADIR}/
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Please add the following to your .weatherrc in order to use installed data files:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "[default]"
	@${ECHO_MSG} "setpath = ${DATADIR}"
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
