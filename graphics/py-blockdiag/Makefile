# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	blockdiag
PORTVERSION=	1.5.4
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Simple block-diagram image generator

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>=2.2.1:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}funcparserlib>=0.3.6:devel/py-funcparserlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webcolors>=0:graphics/py-webcolors@${PY_FLAVOR}

USES=	python:-3.4
USE_PYTHON=	autoplist distutils

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

PORTDOCS=	README.rst
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES IPAFONT PDF
IPAFONT_DESC=	Use IPA Font as default
PDF_DESC=	Enable PDF output

OPTIONS_DEFAULT=	PDF

IPAFONT_RUN_DEPENDS=	${LOCALBASE}/share/font/ipa/ipag.otf:japanese/font-ipa
PDF_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}reportlab>0:print/py-reportlab@${PY_FLAVOR}

post-patch:
	${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/src/blockdiag/utils/bootstrap.py

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
