# $FreeBSD$

PORTNAME=	cfiles
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.2
CATEGORIES=	deskutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Ncurses file manager written in C with vim-like keybindings

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

#RUN_DEPENDS=	${LOCALBASE}/libexec/w3m/w3mimgdisplay:www/w3m # w3mimgdisplay is used from scripts/displayimg but www/w3m doesn't install it by default
RUN_DEPENDS=	bash:shells/bash

USES=		ncurses:port pkgconfig shebangfix
SHEBANG_FILES=	scripts/*
USE_GITHUB=	yes
GH_ACCOUNT=	mananapr

MAKE_ARGS=	CC=${CC}

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz \
		${DATADIR}/scripts/clearimg \
		${DATADIR}/scripts/clearimg_uberzug \
		${DATADIR}/scripts/displayimg \
		${DATADIR}/scripts/displayimg_uberzug

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/share/cfiles/scripts
.for s in clearimg displayimg displayimg_uberzug clearimg_uberzug
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/${s} ${STAGEDIR}${PREFIX}/share/cfiles/scripts
.endfor
	${INSTALL_MAN} ${WRKSRC}/cfiles.1 ${STAGEDIR}${MAN5PREFIX}/man/man1

.include <bsd.port.mk>
