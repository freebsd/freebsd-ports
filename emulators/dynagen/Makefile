# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	dynagen
PORTVERSION=	0.11.0
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dyna-gen/${PORTNAME}%20source%20_%20Linux/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	pavelivolkov@gmail.com
COMMENT=	Text-based front end for Dynamips development version

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}configobj>=4.4.0:${PORTSDIR}/devel/py-configobj \
		dynamips:${PORTSDIR}/emulators/dynamips-community

PLIST_FILES=	bin/dynagen \
		"@sample etc/dynagen.ini.sample" \
		%%PYTHON_SITELIBDIR%%/confConsole.py \
		%%PYTHON_SITELIBDIR%%/confConsole.pyc \
		%%PYTHON_SITELIBDIR%%/confConsole.pyo \
		%%PYTHON_SITELIBDIR%%/console.py \
		%%PYTHON_SITELIBDIR%%/console.pyc \
		%%PYTHON_SITELIBDIR%%/console.pyo \
		%%PYTHON_SITELIBDIR%%/dynamips_lib.py \
		%%PYTHON_SITELIBDIR%%/dynamips_lib.pyc \
		%%PYTHON_SITELIBDIR%%/dynamips_lib.pyo \
		%%PYTHON_SITELIBDIR%%/pemu_lib.py \
		%%PYTHON_SITELIBDIR%%/pemu_lib.pyc \
		%%PYTHON_SITELIBDIR%%/pemu_lib.pyo \
		%%PYTHON_SITELIBDIR%%/pemubin.py \
		%%PYTHON_SITELIBDIR%%/pemubin.pyc \
		%%PYTHON_SITELIBDIR%%/pemubin.pyo \
		%%PYTHON_SITELIBDIR%%/pemuwrapper.py \
		%%PYTHON_SITELIBDIR%%/pemuwrapper.pyc \
		%%PYTHON_SITELIBDIR%%/pemuwrapper.pyo

PORTDOCS=	*
PORTEXAMPLES=	*
PORTDATA=	*

USES=		dos2unix
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
ALL_TARGET=	# empty

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dynagen ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/dynagen.ini ${STAGEDIR}${PREFIX}/etc/dynagen.ini.sample

	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/configspec ${STAGEDIR}${DATADIR}/configspec

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/tutorial.htm ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/tutorial_files
	${INSTALL_DATA} ${WRKSRC}/docs/tutorial_files/* ${STAGEDIR}${DOCSDIR}/tutorial_files

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/sample_labs
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/sample_labs/ethernet_switch
	${INSTALL_DATA} ${WRKSRC}/sample_labs/ethernet_switch/ethsw1.net ${STAGEDIR}${EXAMPLESDIR}/sample_labs/ethernet_switch
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/sample_labs/frame_relay
	${INSTALL_DATA} ${WRKSRC}/sample_labs/frame_relay/frame_relay1.net ${STAGEDIR}${EXAMPLESDIR}/sample_labs/frame_relay
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/sample_labs/multiserver
	${INSTALL_DATA} ${WRKSRC}/sample_labs/multiserver/multiserver.net ${STAGEDIR}${EXAMPLESDIR}/sample_labs/multiserver
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/sample_labs/pix
	${INSTALL_DATA} ${WRKSRC}/sample_labs/pix/pixtest.net ${STAGEDIR}${EXAMPLESDIR}/sample_labs/pix
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/sample_labs/simple1
	${INSTALL_DATA} ${WRKSRC}/sample_labs/simple1/simple1.net ${STAGEDIR}${EXAMPLESDIR}/sample_labs/simple1
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/sample_labs/simple2
	${INSTALL_DATA} ${WRKSRC}/sample_labs/simple2/simple2.net ${STAGEDIR}${EXAMPLESDIR}/sample_labs/simple2
	${INSTALL_DATA} ${WRKSRC}/sample_labs/all_config_options.txt ${STAGEDIR}${EXAMPLESDIR}/sample_labs

.include <bsd.port.mk>
