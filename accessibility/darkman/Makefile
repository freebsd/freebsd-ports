PORTNAME=	darkman
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.1
PORTREVISION=	8
CATEGORIES=	accessibility wayland

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework for dark-mode and light-mode transitions
WWW=		https://gitlab.com/WhyNotHugo/darkman

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		go:modules
USE_GITHUB=	nodefault
USE_GITLAB=	yes
GH_TUPLE=	adrg:xdg:v0.3.3:adrg_xdg/vendor/github.com/adrg/xdg \
		go-check:check:41f04d3bba15:go_check_check/vendor/gopkg.in/check.v1 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		godbus:dbus:v5.0.4:godbus_dbus_v5/vendor/github.com/godbus/dbus/v5 \
		inconshreveable:mousetrap:v1.1.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		kr:pretty:v0.2.0:kr_pretty/vendor/github.com/kr/pretty \
		rxwycdh:rxhash:10b7a38b400d:rxwycdh_rxhash/vendor/github.com/rxwycdh/rxhash \
		sj14:astral:v0.1.2:sj14_astral/vendor/github.com/sj14/astral \
		spf13:cobra:v1.7.0:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag
GL_ACCOUNT=	WhyNotHugo
GO_TARGET=	./cmd/${PORTNAME}
PLIST_FILES=	bin/${PORTNAME} \
		share/dbus-1/services/nl.whynothugo.darkman.service \
		share/dbus-1/services/org.freedesktop.impl.portal.desktop.darkman.service  \
		share/xdg-desktop-portal/portals/${PORTNAME}.portal

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz

post-patch:
# Extract (snapshot) version from the port instead of placeholder
	@${REINPLACE_CMD} 's/0.0.0-dev/${DISTVERSIONFULL}/' \
		${WRKSRC}/cmd/${PORTNAME}/main.go
# Respect PREFIX for system-wide config
	@${REINPLACE_CMD} 's,/etc,${PREFIX}&,' \
		${WRKSRC}/configuration.go
# Respect LOCALBASE for {dark,light}-mode.d scripts
	@${REINPLACE_CMD} 's,/usr/share,${DATADIR:H},' \
		${WRKSRC}/${PORTNAME}.1.scd
	@${REINPLACE_CMD} 's,/usr/share,${LOCALBASE}/share,' \
		${WRKSRC}/vendor/github.com/adrg/xdg/paths_unix.go
# Respect PREFIX for DBus activation
	@${REINPLACE_CMD} 's,/usr/bin,${PREFIX}/bin,' \
		${WRKSRC}/contrib/dbus/*.service

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/dbus-1/services
	${INSTALL_DATA} ${WRKSRC}/contrib/dbus/*.service \
		${STAGEDIR}${PREFIX}/share/dbus-1/services/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/xdg-desktop-portal/portals
	${INSTALL_DATA} ${WRKSRC}/contrib/portal/${PORTNAME}.portal \
		${STAGEDIR}${PREFIX}/share/xdg-desktop-portal/portals/

do-build-MANPAGES-on:
	scdoc < ${WRKSRC}/${PORTNAME}.1.scd >${WRKSRC}/${PORTNAME}.1

do-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/${MANPAGES_PLIST_FILES:H}

.include <bsd.port.mk>
