# New ports collection makefile for:	fceu
# Date Created:		10 Mov 2002
# Whom:			HIYAMA Takeshi <gibbon@cocoa.freemail.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	fceu
PORTVERSION=	0.96
CATEGORIES=	emulators
MASTER_SITES=	http://fceultra.sourceforge.net/files/
DISTNAME=	fceu${PORTVERSION:S/.//}src
#DISTFILES=	${DISTNAME}${PORTVERSION:S/.//}src${EXTRACT_SUFX}

MAINTAINER=	gibbon@cocoa.freemail.ne.jp
COMMENT=	A portable NES/Famicom emulator based on Bero's original FCE

LIB_DEPENDS=	SDL-1.1:${PORTSDIR}/devel/sdl12

WRKSRC=		${WRKDIR}/fceu
USE_X_PREFIX=	yes
USE_GMAKE=	yes
MAKEFILE=	Makefile.unixsdl
USE_REINPLACE=	yes

DOCS=		AUTHORS COPYING ChangeLog FAQ README \
		TODO cheat.txt fcs.txt porting.txt rel/readme-linux.txt
TECHDOCS=	README.now README.sound UNIF_current.txt nsfspec.txt
TECHCPUDOC=	4017.txt 6502_cpu.txt NESSOUND.txt dmc.txt
TECHEXPDOCS=	mmc5-e.txt mmc5_bank_switch.txt
TECHPPUDOCS=	loopy1.txt loopy2.txt timing.txt

.if defined(WITH_OPTIMIZED_FLAGS)
CFLAGS+=        -O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -malign-double
.if (${MACHINE_ARCH} == "i386")
CFLAGS+=        -mcpu=i686 -march=i686 -mfancy-math-387
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

.if defined(TECH_DOC_INSTALL)
PLIST_SUB=	TECHDOCS=""
.else
PLIST_SUB=	TECHDOCS="@comment "
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's+%%LOCALBASE%%+${LOCALBASE}+g;' ${WRKSRC}/Makefile.unixsdl
	@${REINPLACE_CMD} -e 's+%%CFLAGS%%+${CFLAGS}+g;' ${WRKSRC}/Makefile.unixsdl
.if (${ARCH} == "alpha")
	@${REINPLACE_CMD} -e 's|-DC80x86||g' ${WRKSRC}/Makefile.unixsdl
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fceu ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docs in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/Documentation/${docs} ${DOCSDIR}
.endfor
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
	${INSTALL_DATA} ${WRKSRC}/Documentation/tech/ppu/${docs} \
			${DOCSDIR}/tech/ppu
.endfor
.endif
.endif

.include <bsd.port.post.mk>
