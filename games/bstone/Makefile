# $FreeBSD$

PORTNAME=	bstone
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.9
PORTREVISION=	3
CATEGORIES=	games

MAINTAINER=	devel@stasyan.com
COMMENT=	Source port of Blake Stone

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/../LICENSE

USES=		cmake compiler:c++11-lang localbase:ldflags pkgconfig sdl
USE_GITHUB=	yes
GH_ACCOUNT=	bibendovsky
USE_SDL=	sdl2
WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/bstone

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bstone ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../CHANGELOG.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
