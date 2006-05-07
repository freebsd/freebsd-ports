# New ports collection makefile for:	fceu
# Date Created:		10 Mov 2002
# Whom:			HIYAMA Takeshi <gibbon@cocoa.freemail.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	fceu
PORTVERSION=	0.98.13
CATEGORIES=	emulators
MASTER_SITES=	http://bsd-unix.org/downloads/
DISTNAME=	${PORTNAME}-${PORTVERSION}-pre.src

MAINTAINER=	xcas@cox.net
COMMENT=	A portable NES/Famicom emulator based on Bero's original FCE

USE_BZIP2=	yes
USE_GCC=	3.4
USE_GMAKE=	yes
USE_SDL=	sdl
USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}/fceu

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

MAN6=		fceu.6

PLIST_FILES=	bin/fceu %%DOCSDIR%%/cheat.html %%DOCSDIR%%/faq.html \
		%%DOCSDIR%%/fceultra.html %%DOCSDIR%%/fcm.txt \
		%%DOCSDIR%%/fcs.txt %%DOCSDIR%%/protocol.txt
PLIST_DIRS=	%%DOCSDIR%%

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		"Does not compile on sparc64"
.endif

post-extract:
	${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//' ${WRKSRC}/src/drivers/common/vidblit.c

pre-build:
	@${CP} ${WRKSRC}/Documentation/fceu-sdl.6 ${WRKSRC}/Documentation/fceu.6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/fceu ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/Documentation/fceu.6 ${PREFIX}/man/man6
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation/cheat.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation/faq.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation/fceultra.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation/fcm.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation/fcs.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation/protocol.txt ${DOCSDIR}

.include <bsd.port.post.mk>
