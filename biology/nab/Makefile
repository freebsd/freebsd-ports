# New ports collection Makefile for: nab
# Date created:         Sept. 10, 2000
# Whom:                 M. L. Dodson <bdodson@scms.utmb.edu>
#
# $FreeBSD$
#

PORTNAME=	nab
PORTVERSION=	4.5.2
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.scripps.edu/pub/case/ \
		http://www.scripps.edu/case/

MAINTAINER=	bdodson@scms.utmb.edu
COMMENT=	\
 "This is nab (nucleic acid builder), a language for macromolecules"

BUILD_DEPENDS=	ucpp:${PORTSDIR}/devel/ucpp

ONLY_FOR_ARCHS= i386

MAKE_ENV+=	NABHOME=${WRKSRC} ARCH= PATH=${WRKSRC}/bin:${PATH}

MAN1=		nab.1
MANCOMPRESSED=	yes
USE_REINPLACE=	yes

BINARIES=	matextract      matmul          teLeap          tss_main \
		matgen          nab             transform       tss_next \
		matmerge        nab2c           tss_init

LIBRARIES=	cifparse.a      libnab.a        libsym.a

INCS=	defreal.h       nab.h           nabcode.h       nabtypes.h

post-extract:
	@${CP} ${FILESDIR}/config.h ${WRKSRC}

pre-patch:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/cifparse/cifparse.c

post-patch:
	@${RM} -f ${WRKSRC}/examples/program_7.nab.orig
	@${RM} -f ${WRKSRC}/examples/program_1.c \
		${WRKSRC}/examples/program_1.exe
	@${RM} -f ${WRKSRC}/test/1ubq/a.exe
	@${RM} -f ${WRKSRC}/test/1ubq/rattle_min.c
	@${RM} -f ${WRKSRC}/test/1ubq/runleap.c
	@${RM} -f ${WRKSRC}/test/*.exe
	@${RM} -f ${WRKSRC}/tleap/utilMakeHelp.exe
	@${RM} -f ${WRKSRC}/fd_data/abdna.dat.old
	@${RM} -f ${WRKSRC}/reslib/leap/parm94.dat~
	@(cd ${WRKSRC}/reslib/leap && \
		${FIND} . -type f -print | ${GREP} -v '\./[a-zA-Z0-9]' | \
			${XARGS} ${RM} -f)

pre-install:
	@cd ${WRKSRC}/src && \
		${SETENV} PREFIX=${PREFIX} ${MAKE} beforerealinstall

do-install:
	@-${MKDIR} ${PREFIX}/share/nab
	@-${MKDIR} ${PREFIX}/share/nab/bin
	@-${MKDIR} ${PREFIX}/share/nab/include
	@-${MKDIR} ${PREFIX}/share/nab/lib
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC} && (${TAR} cf - examples test peptide suppose | \
		(cd ${PREFIX}/share/nab; ${TAR} xf -))
	@-${MKDIR} ${PREFIX}/share/doc/nab
	${INSTALL_MAN} ${WRKSRC}/doc/NAB.pdf ${PREFIX}/share/doc/nab
.endif
	@cd ${WRKSRC} && (${TAR} cf - dgdb reslib fd_data | \
		(cd ${PREFIX}/share/nab; ${TAR} xf -))
	@(cd ${PREFIX}/share; ${CHOWN} -R ${SHAREOWN}:${SHAREGRP} nab; \
		${CHMOD} -R ugo+rX-w nab)
	@-(cd ${PREFIX}/share/nab && ${LN} -sf ../NDB coords)
	${INSTALL_PROGRAM} ${WRKSRC}/bin/*     ${PREFIX}/bin
	${INSTALL_DATA}    ${WRKSRC}/include/* ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/*     ${PREFIX}/lib
	@-cd ${WRKSRC}/doc && ${GZIP_CMD} ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/doc/nab.1.gz ${PREFIX}/man/man1
.for f in ${BINARIES}
	@cd ${PREFIX}/share/nab/bin && ${LN} -sf ../../../bin/${f} .
.endfor
.for f in ${LIBRARIES}
	@cd ${PREFIX}/share/nab/lib && ${LN} -sf ../../../lib/${f} .
.endfor
.for f in ${INCS}
	@cd ${PREFIX}/share/nab/include && ${LN} -sf ../../../include/${f} .
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
