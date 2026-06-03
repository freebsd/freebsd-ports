PORTNAME=	sowon
DISTVERSION=	g20251203
CATEGORIES=	deskutils

MAINTAINER=	nsonack@herrhotzenplotz.de
COMMENT=	Graphical countdown and timer application
WWW=		https://github.com/tsoding/sowon/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		dos2unix gl gmake localbase xorg
DOS2UNIX_FILES=	thirdparty/RGFW.h
USE_GITHUB=	yes
GH_ACCOUNT=	tsoding
GH_TAGNAME=	79b0f4fa3a3f3a6a702e9d25e69d9d7b1f011a06
USE_GL=		gl
USE_XORG=	x11 xcursor xi xrandr
MAKE_ARGS=	COMMON_CFLAGS="${CFLAGS} -Wall -Wextra -ggdb -std=c99 \
			-pedantic -Ithirdparty -Ibuild -DPENGER" \
		COMMON_LIBS="${LIBS} -lm"

PLIST_FILES=	bin/sowon \
		share/man/man6/sowon.6.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sowon ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/sowon.6.gz \
		${STAGEDIR}${PREFIX}/share/man/man6

.include <bsd.port.mk>
