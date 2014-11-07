# $FreeBSD$

PORTNAME=	git-review
PORTVERSION=	1.24
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	dereckson@gmail.com
COMMENT=	Allow to push review and interact with a Gerrit server

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>0:${PORTSDIR}/devel/py-pbr
RUN_DEPENDS=	git:${PORTSDIR}/devel/git

USES=		python
USE_PYTHON=	distutils autoplist

PLIST_FILES=	man/man1/git-review.1.gz
PORTDOCS=	README.rst HACKING.rst AUTHORS

.include <bsd.port.options.mk>

post-install:
	${INSTALL_MAN} ${WRKSRC}/git-review.1 ${STAGEDIR}${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.endif
.include <bsd.port.mk>
