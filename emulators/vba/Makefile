# New ports collection makefile for:	vba
# Date Created:				02 September 2003
# Whom:					<arundel@gmx.net>
#
# $FreeBSD$

PORTNAME=	vba
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	VisualBoyAdvance-src-${PORTVERSION}

MAINTAINER=	arundel@gmx.net
COMMENT=	Currently the best Gameboy Advance emulator!

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-profiling
USE_SDL=	yes
WRKSRC=		${WRKDIR}/VisualBoyAdvance-${PORTVERSION}

TARGET_DIR=	${PREFIX}/bin/

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
CFLAGS+=	-O0
.else
CLAGS+=
.endif

DATA_FILES=	${WRKSRC}/src/VisualBoyAdvance.cfg
PROG_FILES=	${WRKSRC}/src/VisualBoyAdvance
DOC_FILES=	${WRKSRC}/COPYING ${WRKSRC}/AUTHORS ${WRKSRC}/NEWS ${WRKSRC}/README

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "GCC must be 3.x or greater in order to compile GBA.cpp with -O2. Earlier"
	@${ECHO_MSG} "versions have a problem during optimization that requires an absurd"
	@${ECHO_MSG} "ammount of memory and usually ends up crashing the compiler/computer"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Note by MAINTAINER: Currently everything < 500035 is being build with -O0"
	@${ECHO_MSG} "flag."
	@${ECHO_MSG} ""

post-extract:
	rm -rf `find ${WRKSRC} -name '.deps'`

do-install:
	${INSTALL} -d ${TARGET_DIR} && \
	${INSTALL_PROGRAM} ${PROG_FILES} ${TARGET_DIR} && \
	${INSTALL_DATA} ${DATA_FILES} ${TARGET_DIR} && \

post-install:
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${DOC_FILES} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
