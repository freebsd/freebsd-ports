# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>

PORTNAME=	weather
PORTVERSION=	2.4.1
CATEGORIES=	astro python
MASTER_SITES=	http://fungi.yuggoth.org/weather/src/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utility to provide current weather conditions and forecasts

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python shebangfix tar:xz

NO_ARCH=	yes
NO_BUILD=	yes

SHEBANG_FILES=	weather

do-install:
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/weather ${STAGEDIR}${PREFIX}/bin/weather
	${INSTALL_DATA} ${WRKSRC}/weather.py ${STAGEDIR}${PYTHON_SITELIBDIR}/
	${PYTHON_CMD} -m compileall -d ${PYTHON_SITELIBDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${PYTHON_CMD} -O -m compileall -d ${PYTHON_SITELIBDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_MAN} ${WRKSRC}/weather.1 ${STAGEDIR}${PREFIX}/share/man/man1/weather.1
	${INSTALL_MAN} ${WRKSRC}/weatherrc.5 ${STAGEDIR}${PREFIX}/share/man/man5/weatherrc.5
	${MKDIR} ${STAGEDIR}${DATADIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} airports places stations zctas zones ${STAGEDIR}${DATADIR}/
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Please add the following to your .weatherrc in order to use installed data files:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "[default]"
	@${ECHO_MSG} "setpath = ${DATADIR}"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
