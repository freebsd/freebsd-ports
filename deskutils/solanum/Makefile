PORTNAME=	solanum
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.1
PORTREVISION=	7
CATEGORIES=	deskutils

PATCH_SITES=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/-/commit/
PATCHFILES+=	e5c5d88f95b0.patch:-p1 # https://gitlab.gnome.org/World/Solanum/-/merge_requests/49

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Pomodoro timer for the GNOME desktop
WWW=		https://gitlab.gnome.org/World/Solanum

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cargo gettext gnome gstreamer meson pkgconfig python:build shebangfix
USE_GITLAB=	yes
USE_GNOME=	gtk40 libadwaita
USE_GSTREAMER=	bad good vorbis
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World
GL_PROJECT=	Solanum
GL_COMMIT=	3f84b1d0c46fe1a3daef2940b1d0747222023984
SHEBANG_FILES=	build-aux/meson/postinstall.py
MAKE_ENV=	${CARGO_ENV}
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
GLIB_SCHEMAS=	org.gnome.Solanum.gschema.xml

post-patch:
# Make each cargo subcommand very verbose
	@${REINPLACE_CMD} -e '/cargo/s/ --/&verbose&verbose&/' \
		${WRKSRC}/build-aux/cargo.sh

.include <bsd.port.mk>
