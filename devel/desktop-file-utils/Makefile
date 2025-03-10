PORTNAME=	desktop-file-utils
PORTVERSION=	0.28
CATEGORIES=	devel
MASTER_SITES=	http://freedesktop.org/software/${PORTNAME}/releases/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Couple of command line utilities for working with desktop entries
WWW=		https://www.freedesktop.org/wiki/Software/desktop-file-utils/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 gettext-runtime meson gnome pkgconfig trigger tar:xz
USE_GNOME=	glib20

MIMEDIRS=	share/applications
SUB_FILES=	pkg-post-install.lua
SUB_LIST=	MIMEDIRS="${MIMEDIRS}"
PKGPOSTINSTALL=	${WRKDIR}/pkg-post-install

post-install:
	${INSTALL_DATA} ${WRKSRC}/misc/desktop-entry-mode.el \
		${STAGEDIR}${PREFIX}/share/emacs/site-lisp/desktop-entry-mode.el

.include <bsd.port.mk>
