PORTNAME=	open-simh
PORTVERSION=	4.1.0.20240303
CATEGORIES=	emulators

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Emulates classic DEC, HP, GRI, IBM, Altair, SDS, Honeywell, and others
WWW=		https://opensimh.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf:x11-fonts/dejavu
LIB_DEPENDS=	libpcre.so:devel/pcre \
		libpng16.so:graphics/png
RUN_DEPENDS=	${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf:x11-fonts/dejavu

USES=		dos2unix gmake libedit sdl
DOS2UNIX_GLOB=	*.c *.h *.ini *.mak *.txt makefile

USE_GITHUB=	yes

GH_ACCOUNT=	open-simh
GH_PROJECT=	simh
GH_TAGNAME=	d4f85d01bdf7301d5f7a2c4e51c3a84024561b26

USE_SDL=	sdl2 ttf2

MAKEFILE=	makefile
MAKE_ENV=	CFLAGS_O="${CFLAGS}" \
		FONTPATH="${PREFIX}/share/fonts/dejavu" \
		GCC="${CC}" \
		TESTS=0 \
		WARNINGS=ALLOWED

CONFLICTS_INSTALL=	simh simh-hp2100 simh-hp3000

.include <bsd.port.pre.mk>

post-extract:
	@${MKDIR} ${WRKSRC}/BIN

post-build:
# eclipse, gri and nova conflict with other ports, prefix with simh-
	@${MV} ${WRKSRC}/BIN/eclipse ${WRKSRC}/BIN/simh-eclipse
	@${MV} ${WRKSRC}/BIN/gri ${WRKSRC}/BIN/simh-gri
	@${MV} ${WRKSRC}/BIN/nova ${WRKSRC}/BIN/simh-nova

do-install:
	@${RM} -rf ${WRKSRC}/BIN/buildtools
	${INSTALL_PROGRAM} ${WRKSRC}/BIN/* ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
