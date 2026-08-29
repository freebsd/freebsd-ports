PORTNAME=       SmallBASIC
DISTVERSIONPREFIX= v
DISTVERSION=	12_33
DISTVERSIONSUFFIX= _FreeBSD
CATEGORIES=	lang

MAINTAINER=	mehul.sanghvi@gmail.com
COMMENT=	Interpreter for the BASIC programming language
WWW=		https://smallbasic.github.io/

LICENSE=	GPLv3

USES=		autoreconf pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	smallbasic
GH_TUPLE=	zserge:jsmn:25647e692c7906b96ffd2b05ca54c097948e879c:jsmn/src/lib/jsmn \
		dr-soft:miniaudio:0.11.22:miniaudio/src/lib/miniaudio \
		nothings:stb:f58f558c120e9b32c217290b80bad1a0729fbb2c:stb/src/lib/stb \
		lvandeve:lodepng:17d08dd26cac4d63f43af217ebd70318bfb8189c:lodepng/src/lib/lodepng

GNU_CONFIGURE=	yes

PORTEXAMPLES= *

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/samples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
