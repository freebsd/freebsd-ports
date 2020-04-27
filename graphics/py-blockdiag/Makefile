# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	blockdiag
PORTVERSION=	2.0.1
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Simple block-diagram image generator

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}funcparserlib>=0.3.6:devel/py-funcparserlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webcolors>=0:graphics/py-webcolors@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

PORTDOCS=	README.rst
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES PDF
OPTIONS_DEFAULT=	PDF

OPTIONS_RADIO=	FONT
OPTIONS_RADIO_FONT=	IPA MPLUSIPA VLGOTHIC

IPA_DESC=	Use IPA Font as default
MPLUSIPA_DESC=	Use M-plus IPA Font as default
VLGOTHIC_DESC=	Use VLGothic Font as default
PDF_DESC=	Enable PDF output

IPA_RUN_DEPENDS=	${LOCALBASE}/share/fonts/ipa/ipagp.otf:japanese/font-ipa
MPLUSIPA_RUN_DEPENDS=	${LOCALBASE}/share/fonts/mplus-ipa/fonts/ipagp.ttf:japanese/font-mplus-ipa
VLGOTHIC_RUN_DEPENDS=	${LOCALBASE}/share/fonts/vlgothic/VL-PGothic-Regular.ttf:japanese/font-vlgothic
PDF_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}reportlab>0:print/py-reportlab@${PY_FLAVOR}

post-patch:
	${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/src/blockdiag/utils/bootstrap.py

post-patch-IPA-on:
	${REINPLACE_CMD} '/fontfiles = \[/,/\]/{/fontfiles = \[/H;/ipagp\.otf/H;/\]/H;/\]/!d;g;}' ${WRKSRC}/src/blockdiag/utils/bootstrap.py

post-patch-MPLUSIPA-on:
	${REINPLACE_CMD} '/fontfiles = \[/,/\]/{/fontfiles = \[/H;/ipagp\.ttf/H;/\]/H;/\]/!d;g;}' ${WRKSRC}/src/blockdiag/utils/bootstrap.py

post-patch-VLGOTHIC-on:
	${REINPLACE_CMD} '/fontfiles = \[/,/\]/{/fontfiles = \[/H;/VL-PGothic-Regular\.ttf/H;/\]/H;/\]/!d;g;}' ${WRKSRC}/src/blockdiag/utils/bootstrap.py

post-install:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1/
	@${ECHO_CMD} man/man1/${PORTNAME}.1.gz >> ${TMPPLIST}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/examples/${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
