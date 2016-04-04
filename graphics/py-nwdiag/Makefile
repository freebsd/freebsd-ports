# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nwdiag
PORTVERSION=	1.0.3
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Simple network-diagram image generator

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PKGNAMEPREFIX}pillow>=2.2.1:graphics/py-pillow \
		${PKGNAMEPREFIX}funcparserlib>=0.3.6:devel/py-funcparserlib \
		${PKGNAMEPREFIX}blockdiag>=1.4.1:graphics/py-blockdiag

USES=	python
USE_PYTHON=	autoplist distutils

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGBASE}

PORTDOCS=	README.rst
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} == 3.1
IGNORE=	does not support in ${PYTHON_VERSION}
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for d in ${PORTNAME} packetdiag
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/${d}
	${INSTALL_DATA} \
		${INSTALL_WRKSRC}/examples/${d}/${PORTEXAMPLES} \
		${STAGEDIR}${EXAMPLESDIR}/${d}
.endfor
.for f in ${PORTNAME} rackdiag
	${INSTALL_MAN} ${WRKSRC}/${f}.1 ${STAGEDIR}${PREFIX}/man/man1/
	@${ECHO_CMD} man/man1/${f}.1.gz >> ${TMPPLIST}
.endfor

.include <bsd.port.post.mk>
