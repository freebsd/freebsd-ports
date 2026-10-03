PORTNAME=	vhs
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.1
CATEGORIES=	graphics

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Your CLI home video recorder
WWW=		https://github.com/charmbracelet/vhs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash>0:shells/bash \
		ffmpeg>0:multimedia/ffmpeg \
		ttyd>0:sysutils/ttyd

USES=		go:modules
GO_MODULE=	github.com/charmbracelet/vhs
GO_BUILDFLAGS=	-ldflags "\
			-X 'main.Version=${DISTVERSIONPREFIX}${DISTVERSION}' \
			-X 'main.CommitSHA=${GITID}'"

PLIST_FILES=	bin/vhs

OPTIONS_RADIO=			BROWSER
OPTIONS_RADIO_BROWSER=		CHROMIUM UNGOOGLED_CHROMIUM
BROWSER_DESC=			Browser driver to web automation and scraping
CHROMIUM_DESC=			Install google chromium
UNGOOGLED_CHROMIUM_DESC=	Install ungoogled-chromium

CHROMIUM_RUN_DEPENDS=		chromium>0:www/chromium
UNGOOGLED_CHROMIUM_RUN_DEPENDS=	ungoogled-chromium>0:www/ungoogled-chromium

# Run 'git checkout ${DISTVERSIONPREFIX}${DISTVERSION} && git rev-parse HEAD'
# in the VHS repository to get the value of GITID.
GITID=		24fa2254a9806091e6ee6a980e9f3bcfe0a9ba53

.include <bsd.port.mk>
