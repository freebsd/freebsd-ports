# Created by: Dima Dorfman <dima@unixfreak.org>
# $FreeBSD$

PORTNAME=	mg
PORTVERSION=	6.5
PORTEPOCH=	1
CATEGORIES=	editors
MASTER_SITES=	https://github.com/ibara/mg/releases/download/mg-${PORTVERSION}/

PATCH_SITES=	https://github.com/ibara/mg/commit/
PATCHFILES=	0740c97eff175f90688ac2a4ae08a8f12d5fabcc.patch:-p1

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Small, fast Emacs-like editor

LICENSE=	PD

USES=		ncurses
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
PLIST_FILES=	bin/mg man/man1/mg.1.gz
PORTDOCS=	README-Mg README.md tutorial

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
