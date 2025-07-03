PORTNAME=	health
DISTVERSION=	0.95.0
PORTREVISION=	18
CATEGORIES=	deskutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Track your fitness goals
WWW=		https://gitlab.gnome.org/World/Health

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	blueprint-compiler:devel/blueprint-compiler
LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene \
		libsecret-1.so:security/libsecret \
		libtinysparql-3.0.so:devel/tinysparql

USES=		cargo gettext gnome meson pkgconfig
USE_GITLAB=	yes
USE_GNOME=	cairo gtk40 libadwaita
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World
GL_PROJECT=	Health
MAKE_ENV=	${CARGO_ENV}
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
GLIB_SCHEMAS=	dev.Cogitri.Health.gschema.xml

.if ${MACHINE_ARCH} == i386
# https://github.com/rust-lang/rust/issues/85598
LTO_UNSAFE=	yes
CARGO_ENV+=	CARGO_PROFILE_RELEASE_LTO=false
.endif

post-patch:
# Make each cargo subcommand very verbose
	@${REINPLACE_CMD} -e "/cargo_options =/s/ '--/&verbose', &verbose', &/" \
		${WRKSRC}/src/meson.build

.include <bsd.port.mk>
