# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	actdiag
PORTVERSION=	0.5.1
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Simple activity-diagram image generator

LICENSE=	APACHE20

RUN_DEPENDS=	${PKGNAMEPREFIX}pillow>=2.2.1:${PORTSDIR}/graphics/py-pillow \
		${PKGNAMEPREFIX}blockdiag>=1.3.1:${PORTSDIR}/graphics/py-blockdiag \
		${PKGNAMEPREFIX}funcparserlib>=0.3.6:${PORTSDIR}/devel/py-funcparserlib

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

DOCSDIR=	${PREFIX}/share/doc/${UNIQUENAME}
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
