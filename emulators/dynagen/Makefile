# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	dynagen
PORTVERSION=	0.11.0
PORTREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	SF/dyna-gen/${PORTNAME}%20source%20_%20Linux/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	pavelivolkov@gmail.com
COMMENT=	Text-based front end for Dynamips development version

LICENSE=	GPLv2

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}configobj>=4.4.0:devel/py-configobj@${PY_FLAVOR} \
		dynamips:emulators/dynamips-community

PLIST_FILES=	bin/dynagen "@sample etc/dynagen.ini.sample"

PORTDOCS=	*
PORTEXAMPLES=	*
PORTDATA=	*

USES=		dos2unix python:2.7 shebangfix
SHEBANG_FILES=	*.py dynagen

USE_PYTHON=	distutils autoplist
ALL_TARGET=	# empty
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>

post-extract:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}

post-patch:
.if ${PYTHON_MAJOR_VER} >= 3
	@${ECHO_MSG} "===>   Converting to python${PYTHON_MAJOR_VER}"
	${PYTHONBASE}/bin/2to3-${PYTHON_VER} --no-diffs --write ${WRKSRC} ${WRKSRC}/dynagen
	@${ECHO_MSG} "===>   end of converting"
.endif

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

.include <bsd.port.post.mk>
