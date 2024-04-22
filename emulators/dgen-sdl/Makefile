PORTNAME=	dgen-sdl
PORTVERSION=	1.33
PORTREVISION=	6
CATEGORIES=	emulators
MASTER_SITES=	SF/dgen/dgen/${PORTVERSION}

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Wonderful Sega Genesis/MegaDrive emulator
WWW=		https://dgen.sourceforge.net/

USE_SDL=	sdl
USE_GL=		glu
USES=		gl gmake sdl
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

CONFIGURE_ARGS+=	--disable-asm

PLIST_FILES=	bin/dgen \
		bin/dgen_tobin \
		share/man/man1/dgen.1.gz \
		share/man/man1/dgen_tobin.1.gz \
		share/man/man5/dgenrc.5.gz

.include <bsd.port.mk>
