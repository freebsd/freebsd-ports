PORTNAME=	darkman
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.1
PORTREVISION=	1
CATEGORIES=	accessibility wayland

MAINTAINER=	pierre-alain+freebsd@toret.fr
COMMENT=	Framework for dark-mode and light-mode transitions
WWW=		https://gitlab.com/WhyNotHugo/darkman

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		go:modules
USE_GITHUB=	nodefault
GH_TUPLE=	goccy:go-yaml:v1.18.0:goccy_go_yaml/vendor/github.com/goccy/go-yaml \
		godbus:dbus:v5.0.4:godbus_dbus_v5/vendor/github.com/godbus/dbus/v5 \
		inconshreveable:mousetrap:v1.1.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		lmittmann:tint:v1.1.2:lmittmann_tint/vendor/github.com/lmittmann/tint \
		sj14:astral:v0.2.1:sj14_astral/vendor/github.com/sj14/astral \
		spf13:cobra:v1.7.0:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag
USE_GITLAB=	yes
GL_ACCOUNT=	WhyNotHugo
GO_TARGET=	./cmd/${PORTNAME}

OPTIONS_DEFINE=	EXAMPLES MANPAGES
OPTIONS_DEFAULT=MANPAGES

OPTIONS_SUB=	yes

post-patch:
# Extract (snapshot) version from the port instead of placeholder
	@${REINPLACE_CMD} 's/0.0.0-dev/${DISTVERSIONFULL}/' \
		${WRKSRC}/cmd/${PORTNAME}/main.go
# Respect PREFIX for DBus activation
	@${REINPLACE_CMD} 's,/usr/bin,${PREFIX}/bin,' \
		${WRKSRC}/contrib/dbus/*.service

do-install-EXAMPLES-on:
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR})

do-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
		${STAGEDIR}${MANDIRS}/man1
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.conf.5 \
		${STAGEDIR}${MANDIRS}/man5

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/dbus-1/services
	${INSTALL_DATA} ${WRKSRC}/contrib/dbus/*.service \
		${STAGEDIR}${PREFIX}/share/dbus-1/services/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/xdg-desktop-portal/portals
	${INSTALL_DATA} ${WRKSRC}/contrib/portal/${PORTNAME}.portal \
		${STAGEDIR}${PREFIX}/share/xdg-desktop-portal/portals/
	@${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop \
		${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
