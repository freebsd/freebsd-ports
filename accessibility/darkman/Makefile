PORTNAME=	darkman
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.4
PORTREVISION=	7
CATEGORIES=	accessibility wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Framework for dark-mode and light-mode transitions
WWW=		https://gitlab.com/WhyNotHugo/darkman

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		go:modules
USE_GITHUB=	nodefault
USE_GITLAB=	yes
GH_TUPLE=	adrg:xdg:v0.3.3:adrg_xdg/vendor/github.com/adrg/xdg \
		go-check:check:41f04d3bba15:go_check_check/vendor/gopkg.in/check.v1 \
		go-yaml:yaml:496545a6307b:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		godbus:dbus:v5.0.4:godbus_dbus_v5/vendor/github.com/godbus/dbus/v5 \
		integrii:flaggy:v1.5.2:integrii_flaggy/vendor/github.com/integrii/flaggy \
		kr:pretty:v0.2.0:kr_pretty/vendor/github.com/kr/pretty \
		sj14:astral:v0.1.2:sj14_astral/vendor/github.com/sj14/astral
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
# Respect LOCALBASE for {dark,light}-mode.d scripts
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
