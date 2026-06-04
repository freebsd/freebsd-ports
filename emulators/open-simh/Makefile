PORTNAME=	open-simh
PORTVERSION=	4.1.0.20260507
CATEGORIES=	emulators

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Emulates classic DEC, HP, GRI, IBM, Altair, SDS, Honeywell, and others
WWW=		https://opensimh.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf:x11-fonts/dejavu
LIB_DEPENDS=	libpcre2-8.so:devel/pcre2 \
		libpng16.so:graphics/png
RUN_DEPENDS=	${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf:x11-fonts/dejavu

USES=		dos2unix gmake libedit sdl
DOS2UNIX_GLOB=	*.c *.h *.ini *.mak *.txt makefile

USE_GITHUB=	yes

GH_ACCOUNT=	open-simh
GH_PROJECT=	simh
GH_TAGNAME=	0dc9decac98fc99c8db9722cd5d941b9e73ac67b

USE_SDL=	sdl2 ttf2

MAKEFILE=	makefile
MAKE_ENV=	CFLAGS_O="${CFLAGS}" \
		FONTPATH="${PREFIX}/share/fonts/dejavu" \
		GCC="${CC}" \
		TESTS=0 \
		WARNINGS=ALLOWED

CONFLICTS_INSTALL=	simh simh-hp2100 simh-hp3000

OPTIONS_DEFINE=		VDE
OPTIONS_DEFAULT=	VDE
VDE_DESC=		VDE Ethernet networking support

VDE_LIB_DEPENDS=	libvdeplug.so:net/vde2

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
