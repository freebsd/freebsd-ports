# New ports collection makefile for:	fceu
# Date Created:		10 Mov 2002
# Whom:			HIYAMA Takeshi <gibbon@cocoa.freemail.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	fceu
PORTVERSION=	0.97.5
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://xodnizel.net/fceultra/downloads/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	gibbon@cocoa.freemail.ne.jp
COMMENT=	A portable NES/Famicom emulator based on Bero's original FCE

USE_SDL=	yes
MAN6=		fceu.6
WRKSRC=		${WRKDIR}/fceu
USE_X_PREFIX=	yes
USE_GMAKE=	yes
MAKEFILE=	Makefile.unixsdl
USE_REINPLACE=	yes

DOCS=		AUTHORS COPYING ChangeLog FAQ README TODO \
		cheat.html fceultra.html fcs.txt porting.txt protocol.txt
TECHDOCS=	README.now README.sound UNIF_current.txt nsfspec.txt
TECHCPUDOC=	4017.txt 6502_cpu.txt NESSOUND-4th.txt NESSOUND.txt dmc.txt
TECHEXPDOCS=	SMB2j.txt mmc5-e.txt mmc5_bank_switch.txt tengen.txt \
		vrcvi.txt vrcvii.txt
TECHPPUDOCS=	"2C02_technical_operation.TXT" loopy1.txt loopy2.txt

.if defined(WITH_OPTIMIZED_FLAGS)
CFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -malign-double
.if (${MACHINE_ARCH} == "i386")
CFLAGS+=	-ffast-math -mfancy-math-387
.endif # i386
.endif

pre-everything::
.if !defined(WITH_OPTIMIZED_FLAGS)
	@${ECHO_MSG} "You can optimize by setting WITH_OPTIMIZED_FLAGS=yes."
.endif
.if !defined(NOPORTDOCS) && !defined(TECH_DOC_INSTALL)
	@${ECHO_MSG} "You can install technical documents"
	@${ECHO_MSG} "by defining TECH_DOC_INSTALL"
.endif

.if !defined(NOPORTDOCS) && defined(TECH_DOC_INSTALL)
PLIST_SUB=	TECHDOCS=""
.else
PLIST_SUB=	TECHDOCS="@comment "
.endif

.include <bsd.port.pre.mk>

post-patch:
.if (${MACHINE_ARCH} != "i386")
# do I have to do this for ia64 and amd64 too?
	@${REINPLACE_CMD} -e 's|-DC80x86||g;' ${WRKSRC}/Makefile.unixsdl
.if (${MACHINE_ARCH} == "sparc64")
	@${REINPLACE_CMD} -e 's|-DLSB_FIRST||g;' ${WRKSRC}/Makefile.unixsdl
.endif
.endif

pre-build:
	@${CP} ${WRKSRC}/Documentation/fceu-sdl.6 ${WRKSRC}/Documentation/fceu.6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fceu ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.if !defined(NOPORTDOCS)
.for docs in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/Documentation/${docs} ${DOCSDIR}
.endfor
.endif

.if !defined(NOPORTDOCS)
	${INSTALL_MAN} ${WRKSRC}/Documentation/fceu.6 ${PREFIX}/man/man6
.if defined(TECH_DOC_INSTALL)
	@${MKDIR} ${DOCSDIR}/tech
.for docs in ${TECHDOCS}
	${INSTALL_DATA} ${WRKSRC}/Documentation/tech/${docs} ${DOCSDIR}/tech
.endfor
	@${MKDIR} ${DOCSDIR}/tech/cpu
.for docs in ${TECHCPUDOC}
	${INSTALL_DATA} ${WRKSRC}/Documentation/tech/cpu/${docs} \
			${DOCSDIR}/tech/cpu
.endfor
	@${MKDIR} ${DOCSDIR}/tech/exp
.for docs in ${TECHEXPDOCS}
	${INSTALL_DATA} ${WRKSRC}/Documentation/tech/exp/${docs} \
			${DOCSDIR}/tech/exp
.endfor
	@${MKDIR} ${DOCSDIR}/tech/ppu
.for docs in ${TECHPPUDOCS}
	${INSTALL_DATA} ${WRKSRC}/Documentation/tech/ppu/${docs:S|_| |g} \
			${DOCSDIR}/tech/ppu/${docs}
.endfor
.endif
.endif
.endif

.include <bsd.port.post.mk>
