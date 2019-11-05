# Created by: Jeroen Ruigrok van der Werven <asmodai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tuxnes
PORTVERSION=	0.75
PORTREVISION=	6
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/TuxNES/TuxNES%20v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nintendo Entertainment System 8-bit emulator

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	uses i386 assembly code

USES=		compiler gmake xorg
USE_XORG=	x11 ice sm xext xpm
USE_BINUTILS=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/romfixer bin/tuxnes share/pixmaps/tuxnes.xpm

DESKTOP_ENTRIES="TuxNES" "" "${PREFIX}/share/pixmaps/tuxnes.xpm" \
		"${PORTNAME}" "" ""

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == "clang"
CPPFLAGS+=	-no-integrated-as
.endif
.if ${ARCH} == "i386"
# Build tool "compdata" segfaults when linked with lld
LLD_UNSAFE=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CFLAGS=|#CFLAGS=|' ${WRKSRC}/configure

post-install:
	(cd ${WRKSRC} && ${INSTALL_DATA} tuxnes.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps)

.include <bsd.port.post.mk>
