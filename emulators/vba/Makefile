# New ports collection makefile for:	vba
# Date Created:				02 September 2003
# Whom:					<arundel@gmx.net>
#
# $FreeBSD$

PORTNAME=	vba
PORTVERSION=	1.7.2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	VisualBoyAdvance-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Source Gameboy Advance emulator

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_SDL=	sdl
WRKSRC=		${WRKDIR}/VisualBoyAdvance-${PORTVERSION}

TARGET_DIR=	${PREFIX}/bin/

.include <bsd.port.pre.mk>

.if ( ${OSVERSION} < 500035 )
CFLAGS+=	-O0
.endif

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on 4.x"
.endif

.ifndef(PROFILING)
CONFIGURE_ARGS+=	--without-profiling
.endif

CONFIGURE_ARGS+=	LIBS=-L${LOCALBASE}/lib

DATA_FILES=	${WRKSRC}/src/VisualBoyAdvance.cfg
PROG_FILES=	${WRKSRC}/src/sdl/VisualBoyAdvance ${WRKSRC}/src/sdl/TestEmu
DOC_FILES=	COPYING AUTHORS NEWS README ChangeLog INSTALL

pre-everything::
.ifndef(PROFILING)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You can enable profiling by defining PROFILING."
.endif
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Due to a bug in gcc2 optimsations other than -O0 will be ignored on"
	@${ECHO_MSG} "FreeBSD releases that didn't ship with gcc3 (prior 500035)."
	@${ECHO_MSG} ""

do-install:
	${INSTALL} -d ${TARGET_DIR}
	${INSTALL_PROGRAM} ${PROG_FILES} ${TARGET_DIR}
	${CP} ${DATA_FILES} ${DATA_FILES}-default
	${INSTALL_DATA} ${DATA_FILES}-default ${TARGET_DIR}

post-install:
.ifndef(NOPORTDOCS)
	${INSTALL} -d ${DOCSDIR}
.for filename in ${DOC_FILES}
	${INSTALL_MAN} ${WRKSRC}/${filename} ${DOCSDIR}
.endfor
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
