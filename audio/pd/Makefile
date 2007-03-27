# New ports collection makefile for:	pd
# Date created:				2002-05-24
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	pd
DISTVERSION=	0.40-2
DISTVERSIONSUFFIX=	.src
CATEGORIES=	audio
MASTER_SITES=	http://www-crca.ucsd.edu/~msp/Software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pure Data, a MIDI-capable real-time audio processor/synthesizer

WRKSRC=		${WRKDIR}/${DISTNAME:S;.src;/src;}
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS} -I${X11BASE}/include -I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR}" \
		LIBS="${PTHREAD_LIBS} -L${LOCALBASE}/lib"
MAKEFILE=	makefile
MAN1=		pd.1 pdreceive.1 pdsend.1
PATCH_WRKSRC=	${WRKSRC}/..
PLIST=		${WRKDIR}/pkg-plist
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:259
USE_TCL=	yes
USE_TK=		yes
USE_TCL_BUILD=	yes
USE_TK_BUILD=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		Does not compile on !i386
.endif

pre-patch:
	${RM} -f ${WRKSRC}/configure

post-configure:
	${MV} ${WRKSRC}/makefile ${WRKSRC}/makefile.orig
	${SED} -e "s:^LIB =:LIB =${PTHREAD_LIBS}:g; \
		s:^pddocdir = .*:pddocdir = ${PREFIX}/share/doc/pd:g; \
		s:x_midi.c ::g; s:s_midi.c ::g;" \
		< ${WRKSRC}/makefile.orig > ${WRKSRC}/makefile

pre-install:
	${RM} -f ${PLIST}
.for ii in pd pd-gui pd-watchdog pd.tk pdreceive pdsend
	${ECHO_CMD} bin/${ii} >> ${PLIST}
.endfor
	${ECHO_CMD} include/m_pd.h >> ${PLIST}
.if !defined(NOPORTDOCS)
.for ii in LICENSE README
	${ECHO_CMD} share/doc/pd/${ii}.txt >> ${PLIST}
.endfor
	cd ${WRKSRC}/../doc && ${FIND} -s . -type f | \
		${CUT} -c3-999 | \
		${SED} -e 's:^:share/doc/pd/:' >> ${PLIST} \
		&& ${FIND} -d . -type d | \
		${CUT} -c3-999 | \
		${SED} -e 's:^:@dirrm share/doc/pd/:' >> ${PLIST}
	cd ${WRKSRC}/../extra && ${FIND} -s . -type f -or -type l | \
		${CUT} -c3-999 | \
		${SED} -e 's:^:share/pd/:' >> ${PLIST} \
		&& ${FIND} -d . -type d | \
		${CUT} -c3-999 | \
		${SED} -e 's:^:@dirrm share/pd/:' >> ${PLIST}
.endif

do-install:
.for ii in pd pd-gui pd-watchdog pdreceive pdsend
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/${ii} ${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/../bin/pd.tk ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/m_pd.h ${PREFIX}/include
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for ii in LICENSE README
	${INSTALL_DATA} ${WRKSRC}/../${ii}.txt ${DOCSDIR}
.endfor
	cd ${WRKSRC}/../doc && ${PAX} -r -w * ${DOCSDIR}
.endif
.for ii in pd pdreceive pdsend
	${INSTALL_MAN} ${WRKSRC}/../man/${ii}.1 ${PREFIX}/man/man1/
.endfor
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/../extra && ${PAX} -r -w * ${DATADIR}

.include <bsd.port.post.mk>
