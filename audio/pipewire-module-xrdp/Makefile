PORTNAME=	pipewire-module-xrdp
DISTVERSION=	b20230609
CATEGORIES=	audio

MAINTAINER=	meta@FreeBSD.org
COMMENT=	PipeWire module which enables xrdp to use audio redirection
WWW=		https://github.com/neutrinolabs/pipewire-module-xrdp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire

USES=		autoreconf:build desktop-file-utils libtool pkgconfig
USE_LDCONFIG=	yes
USE_GITHUB=	yes

GH_ACCOUNT=	neutrinolabs
GH_TAGNAME=	e9c6c05

GNU_CONFIGURE=	yes
PLIST_FILES=	lib/pipewire-0.3/libpipewire-module-xrdp-pipewire.so \
		libexec/pipewire-module-xrdp/load_pw_modules.sh \
		xdg/pipewire-xrdp.desktop

CONFIGURE_ARGS+= \
		 --with-xdgautostart-dir=${LOCALBASE}/xdg

pre-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./bootstrap

.include <bsd.port.mk>
