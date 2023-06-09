PORTNAME=	health
DISTVERSION=	0.94.0
PORTREVISION=	10
CATEGORIES=	deskutils

PATCH_SITES=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/-/commit/
PATCHFILES+=	864d961a3c4e.patch:-p1 # https://gitlab.gnome.org/World/Health/-/issues/167
PATCHFILES+=	04e0a01f5e20.patch:-p1 # https://gitlab.gnome.org/World/Health/-/merge_requests/190

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Track your fitness goals
WWW=		https://gitlab.gnome.org/World/Health

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	blueprint-compiler:devel/blueprint-compiler
LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene \
		libsecret-1.so:security/libsecret \
		libtracker-sparql-3.0.so:sysutils/tracker3

USES=		cargo gettext gnome meson pkgconfig
USE_GITLAB=	yes
USE_GNOME=	cairo gtk40 libadwaita
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World
GL_PROJECT=	Health
GL_COMMIT=	d664384370bb55f0e46a78da094c567a5a7e97c6
MAKE_ENV=	${CARGO_ENV}
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
GLIB_SCHEMAS=	dev.Cogitri.Health.gschema.xml

post-patch:
# Make each cargo subcommand very verbose
# Add explicit <triple> subdir for --target from USES=cargo
	@${REINPLACE_CMD} -e "/cargo_options =/s/ '--/&verbose', &verbose', &/" \
		-e "/cp/s,'src',& / '${CARGO_BUILD_TARGET}'," \
		${WRKSRC}/src/meson.build

.include <bsd.port.mk>
