# $FreeBSD$

PORTNAME=	git-review
PORTVERSION=	1.23
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	dereckson@gmail.com
COMMENT=	Allow to push review and interact with a Gerrit server

LICENSE=	APACHE20

RUN_DEPENDS=	git:${PORTSDIR}/devel/git

USE_PYTHON=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/git-review \
		man/man1/git-review.1.gz
PORTDOCS=	README.rst HACKING.rst AUTHORS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/git-review ${STAGEDIR}${PREFIX}/bin/git-review
	${INSTALL_MAN} ${WRKSRC}/git-review.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
