PORTNAME=	desktop-file-utils
PORTVERSION=	0.26
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://freedesktop.org/software/${PORTNAME}/releases/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Couple of command line utilities for working with desktop entries

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 gettext meson gnome pkgconfig trigger tar:xz
USE_GNOME=	glib20

MIMEDIRS=	share/applications
SUB_LIST=	MIMEDIRS="${MIMEDIRS}"
PKGPOSTINSTALL=	${WRKDIR}/pkg-post-install
SUB_FILES=	pkg-post-install.lua

post-install:
	${INSTALL_DATA} ${WRKSRC}/misc/desktop-entry-mode.el \
		${STAGEDIR}${PREFIX}/share/emacs/site-lisp/desktop-entry-mode.el

.include <bsd.port.mk>
