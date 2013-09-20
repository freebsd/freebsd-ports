# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	dynagen
PORTVERSION=	0.11.0
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	SF/dyna-gen/${PORTNAME}%20source%20_%20Linux/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	pavelivolkov@googlemail.com
COMMENT=	Text-based front end for Dynamips development version

LICENSE=	GPLv2

# Note that it *should* be dynamips-devel but that port installs it as dynamips
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}configobj>=4.4.0:${PORTSDIR}/devel/py-configobj \
		dynamips:${PORTSDIR}/emulators/dynamips-community

PLIST_FILES=	bin/dynagen \
		etc/dynagen.ini.sample \
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

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
ALL_TARGET=	# empty
USE_DOS2UNIX=	yes

NO_STAGE=	yes
post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dynagen ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/dynagen.ini ${PREFIX}/etc/dynagen.ini.sample
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/configspec ${DATADIR}/configspec

.ifndef NOPORTDOCS
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/tutorial.htm ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/tutorial_files
	${INSTALL_DATA} ${WRKSRC}/docs/tutorial_files/* ${DOCSDIR}/tutorial_files
.endif

.ifndef NOPORTEXAMPLES
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR}/sample_labs
	@${MKDIR} ${EXAMPLESDIR}/sample_labs/ethernet_switch
	${INSTALL_DATA} ${WRKSRC}/sample_labs/ethernet_switch/ethsw1.net ${EXAMPLESDIR}/sample_labs/ethernet_switch
	@${MKDIR} ${EXAMPLESDIR}/sample_labs/frame_relay
	${INSTALL_DATA} ${WRKSRC}/sample_labs/frame_relay/frame_relay1.net ${EXAMPLESDIR}/sample_labs/frame_relay
	@${MKDIR} ${EXAMPLESDIR}/sample_labs/multiserver
	${INSTALL_DATA} ${WRKSRC}/sample_labs/multiserver/multiserver.net ${EXAMPLESDIR}/sample_labs/multiserver
	@${MKDIR} ${EXAMPLESDIR}/sample_labs/pix
	${INSTALL_DATA} ${WRKSRC}/sample_labs/pix/pixtest.net ${EXAMPLESDIR}/sample_labs/pix
	@${MKDIR} ${EXAMPLESDIR}/sample_labs/simple1
	${INSTALL_DATA} ${WRKSRC}/sample_labs/simple1/simple1.net ${EXAMPLESDIR}/sample_labs/simple1
	@${MKDIR} ${EXAMPLESDIR}/sample_labs/simple2
	${INSTALL_DATA} ${WRKSRC}/sample_labs/simple2/simple2.net ${EXAMPLESDIR}/sample_labs/simple2
	${INSTALL_DATA} ${WRKSRC}/sample_labs/all_config_options.txt ${EXAMPLESDIR}/sample_labs
.endif

pre-deinstall:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGDEINSTALL} ${PKGNAME} DEINSTALL

.include <bsd.port.mk>
