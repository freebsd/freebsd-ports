PORTNAME=	senpai
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
CATEGORIES=	irc

MAINTAINER=	freebsd@bendo.org
COMMENT=	Modern terminal IRC client
WWW=		https://sr.ht/~delthas/${PORTNAME}/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	git.sr.ht/~delthas/${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME}
GO_LDFLAGS+=	-X ${GO_MODULE}.version=${DISTVERSION}

OPTIONS_DEFINE=		DESKTOP MANPAGES
OPTIONS_DEFAULT=	DESKTOP MANPAGES
OPTIONS_SUB=		yes

DESKTOP_DESC=	Install .desktop file and application icons
DESKTOP_USES=	desktop-file-utils

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_USES=		gmake

do-build-MANPAGES-on:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} doc

do-install-DESKTOP-on:
	${INSTALL_DATA} ${WRKSRC}/contrib/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/
	${INSTALL_DATA} ${WRKSRC}/res/icon.48.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/
	${INSTALL_DATA} ${WRKSRC}/res/icon.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/${PORTNAME}.svg

do-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.5 ${STAGEDIR}${PREFIX}/share/man/man5/

.include <bsd.port.mk>
