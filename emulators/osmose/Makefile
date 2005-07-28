# New ports collection makefile for:	osmose
# Date created:				27 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	osmose
PORTVERSION=	0.6.30
CATEGORIES=	emulators
MASTER_SITES=	http://bcz.emu-france.com/osmose/
DISTNAME=	${PORTNAME}-final-src

MAINTAINER=	alejandro@varnet.biz
COMMENT=	Sega Master System emulator

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

ONLY_FOR_ARCHS=	i386

USE_ZIP=	yes
USE_GMAKE=	yes
USE_SDL=	sdl
USE_REINPLACE=	yes

NO_WRKSUBDIR=	yes

OPTIONS=	OPTIMIZED_CFLAGS "Enable compilation optimizations" on

PLIST_FILES=	bin/osmose
PORTDOCS=	readme.txt

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_PATCHES=	${FILESDIR}/extra-patch-freebsd4
.endif

post-patch:
# Fix Makefile
	@${REINPLACE_CMD} -e 's|\(-Dlinux\)|${CFLAGS} \1| ; \
			s|sdl-config|${SDL_CONFIG}|' \
				${WRKSRC}/${MAKEFILE}

# Fix SDL include statement
	@${REINPLACE_CMD} -e 's|\(#include.*\)SDL/\(SDL.*\)|\1\2|' \
				${WRKSRC}/*.h

# Enable/disable compilation optimizations
.if defined(WITHOUT_OPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} -e 's|-O3||g' ${WRKSRC}/${MAKEFILE}
.endif

.include <bsd.port.post.mk>
