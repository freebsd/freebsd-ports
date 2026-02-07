PORTNAME=	nwdiag
PORTVERSION=	3.0.0
PORTREVISION=	3
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Simple network-diagram image generator
WWW=		http://blockdiag.com/en/nwdiag/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}blockdiag>=1.5.0:graphics/py-blockdiag@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGBASE}

PORTDOCS=	README.rst
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
.for f in ${PORTNAME} rackdiag
	${INSTALL_MAN} ${WRKSRC}/${f}.1 ${STAGEDIR}${PREFIX}/share/man/man1/
	@${ECHO_CMD} share/man/man1/${f}.1.gz >> ${TMPPLIST}
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for d in ${PORTNAME} packetdiag
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/${d}
	${INSTALL_DATA} \
		${INSTALL_WRKSRC}/examples/${d}/${PORTEXAMPLES} \
		${STAGEDIR}${EXAMPLESDIR}/${d}
.endfor

.include <bsd.port.mk>
