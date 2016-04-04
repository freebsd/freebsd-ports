# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	actdiag
PORTVERSION=	0.5.3
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Simple activity-diagram image generator

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PKGNAMEPREFIX}pillow>=2.2.1:graphics/py-pillow \
		${PKGNAMEPREFIX}blockdiag>=1.4.1:graphics/py-blockdiag \
		${PKGNAMEPREFIX}funcparserlib>=0.3.6:devel/py-funcparserlib

USES=	python
USE_PYTHON=	autoplist distutils

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}
PORTDOCS=	README.rst

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} == 3.1
IGNORE=	does not support in ${PYTHON_VERSION}
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1/
	@${ECHO_CMD} man/man1/${PORTNAME}.1.gz >> ${TMPPLIST}

.include <bsd.port.post.mk>
