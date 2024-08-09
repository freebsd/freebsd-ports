PORTNAME=	vhs
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.2
PORTREVISION=	3
CATEGORIES=	graphics

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Your CLI home video recorder
WWW=		https://github.com/charmbracelet/vhs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash>0:shells/bash \
		ffmpeg>0:multimedia/ffmpeg \
		ttyd>0:sysutils/ttyd

USES=		go:modules
GO_MODULE=	github.com/charmbracelet/vhs

PLIST_FILES=	bin/vhs

OPTIONS_RADIO=			BROWSER
OPTIONS_RADIO_BROWSER=		CHROMIUM UNGOOGLED_CHROMIUM
BROWSER_DESC=			Browser driver to web automation and scraping
CHROMIUM_DESC=			Install google chromium
UNGOOGLED_CHROMIUM_DESC=	Install ungoogled-chromium

CHROMIUM_RUN_DEPENDS=		chromium>0:www/chromium
UNGOOGLED_CHROMIUM_RUN_DEPENDS=	ungoogled-chromium>0:www/ungoogled-chromium

.include <bsd.port.mk>
