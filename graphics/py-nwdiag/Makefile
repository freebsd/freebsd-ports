# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nwdiag
PORTVERSION=	1.0.4
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Simple network-diagram image generator

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PKGNAMEPREFIX}pillow>=2.2.1:graphics/py-pillow@${FLAVOR} \
		${PKGNAMEPREFIX}funcparserlib>=0.3.6:devel/py-funcparserlib@${FLAVOR} \
		${PKGNAMEPREFIX}blockdiag>=1.5.0:graphics/py-blockdiag@${FLAVOR}

USES=	python:-3.4
USE_PYTHON=	autoplist distutils

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGBASE}

PORTDOCS=	README.rst
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
.for f in ${PORTNAME} rackdiag
	${INSTALL_MAN} ${WRKSRC}/${f}.1 ${STAGEDIR}${PREFIX}/man/man1/
	@${ECHO_CMD} man/man1/${f}.1.gz >> ${TMPPLIST}
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
