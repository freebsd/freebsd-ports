# Created by: Dima Dorfman <dima@unixfreak.org>
# $FreeBSD$

PORTNAME=	mg
PORTVERSION=	6.7
PORTEPOCH=	1
CATEGORIES=	editors
MASTER_SITES=	https://github.com/ibara/mg/releases/download/mg-${PORTVERSION}/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Small, fast Emacs-like editor

LICENSE=	PD

USES=		ncurses
HAS_CONFIGURE=	yes
PLIST_FILES=	bin/mg \
		man/man1/mg.1.gz
PORTDOCS=	README-Mg README.md tutorial

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
