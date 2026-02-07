PORTNAME=	sowon
DISTVERSION=	g20201203
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	nsonack@herrhotzenplotz.de
COMMENT=	Graphical countdown and timer application
WWW=		https://github.com/tsoding/sowon/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		pkgconfig sdl

USE_GITHUB=	yes
GH_ACCOUNT=	tsoding
GH_TAGNAME=	0d43de4af5a430052aee2c2691fafe21ad80a83d

USE_SDL=	sdl2

PLIST_FILES=	bin/sowon \
		share/man/man6/sowon.6.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sowon ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/sowon.6.gz \
		${STAGEDIR}${PREFIX}/share/man/man6

.include <bsd.port.mk>
