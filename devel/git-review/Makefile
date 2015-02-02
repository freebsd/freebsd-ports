# $FreeBSD$

PORTNAME=	git-review
PORTVERSION=	1.24
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	dereckson@gmail.com
COMMENT=	Allow to push review and interact with a Gerrit server

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>0:${PORTSDIR}/devel/py-pbr
RUN_DEPENDS=	git:${PORTSDIR}/devel/git \
		${PYTHON_PKGNAMEPREFIX}requests>2.4:${PORTSDIR}/www/py-requests

USES=		python
USE_PYTHON=	autoplist distutils

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
