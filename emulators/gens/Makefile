# Created by: Travis Poppe <tlp@liquidx.org>
# $FreeBSD$

PORTNAME=	gens
PORTVERSION=	2.15.5
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/Gens%20Source%20Code/Gens%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sega Genesis/CD/32X emulator

LICENSE=	GPLv2

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

OPTIONS_DEFINE=	DOCS

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	uses i386 assembly code

USES=		gmake pkgconfig
USE_GNOME=	gtk20
USE_GL=		gl
USE_SDL=	sdl
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DESKTOP_ENTRIES="Gens" "" "${DATADIR}/gens_small.png" "${PORTNAME}" "" ""

.include <bsd.port.options.mk>

post-patch:
.for i in gens_core/sound/ym2612.h mp3_dec/mpg123.h
	@${REINPLACE_CMD} -e \
		's|\(^#define INLINE\).*|\1 static inline|' \
		${WRKSRC}/src/gens/${i}
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
