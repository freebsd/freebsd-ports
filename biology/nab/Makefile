# New ports collection Makefile for: nab
# Date created:         Sept. 10, 2000
# Whom:                 M. L. Dodson <bdodson@scms.utmb.edu>
#
# $FreeBSD$
#

PORTNAME=	nab
PORTVERSION=	4.4
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.scripps.edu/pub/case/ \
		http://www.scripps.edu/case/

MAINTAINER=	bdodson@scms.utmb.edu

MAKE_ENV+=	NABHOME=${WRKSRC} ARCH= PATH=${WRKSRC}/bin:${PATH}

USE_BISON=	yes
MAN1=		nab.1
MANCOMPRESSED=	yes
USE_REINPLACE=	yes

BINARIES=	matextract      matmul          teLeap          tss_main \
		matgen          nab             transform       tss_next \
		matmerge        nab2c           tss_init        ucpp

LIBRARIES=	cifparse.a      libnab.a        libsym.a

INCS=	defreal.h       nab.h           nabcode.h       nabtypes.h

post-extract:
	@${CP} ${FILESDIR}/config.h ${WRKSRC}

pre-patch:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/cifparse/cifparse.c

post-patch:
	@rm -f ${WRKSRC}/examples/program_7.nab.orig

pre-install:
	@cd ${WRKSRC}/src && \
		${SETENV} PREFIX=${PREFIX} ${MAKE} beforerealinstall

do-install:
	@-mkdir -p ${PREFIX}/share/nab
	@-mkdir -p ${PREFIX}/share/nab/bin
	@-mkdir -p ${PREFIX}/share/nab/include
	@-mkdir -p ${PREFIX}/share/nab/lib
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC} && (tar cf - examples test peptide suppose | \
		(cd ${PREFIX}/share/nab; tar xf -))
	@-mkdir -p ${PREFIX}/share/doc/nab
	${INSTALL_MAN} ${WRKSRC}/doc/NAB.pdf ${PREFIX}/share/doc/nab
.endif
	@cd ${WRKSRC} && (tar cf - dgdb reslib fd_data | \
		(cd ${PREFIX}/share/nab; tar xf -))
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
