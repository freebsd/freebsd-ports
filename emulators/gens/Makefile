# Created by: Travis Poppe <tlp@liquidx.org>
# $FreeBSD$

PORTNAME=	gens
PORTVERSION=	2.15.5
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/Gens%20Source%20Code/Gens%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sega Genesis/CD/32X emulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	nasm:devel/nasm

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	uses i386 assembly code

USES=		gmake gnome gl localbase pkgconfig
USE_GNOME=	gtk20
USE_GL=		gl
USE_SDL=	sdl
GNU_CONFIGURE=	yes

DESKTOP_ENTRIES="Gens" "" "${DATADIR}/gens_small.png" "${PORTNAME}" "" ""

OPTIONS_DEFINE=	DOCS

post-patch:
.for i in gens_core/sound/ym2612.h mp3_dec/mpg123.h
	@${REINPLACE_CMD} -e \
		's|\(^#define INLINE\).*|\1 static inline|' \
		${WRKSRC}/src/gens/${i}
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
