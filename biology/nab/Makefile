# New ports collection Makefile for: nab
# Date created:         Sept. 10, 2000
# Whom:                 M. L. Dodson <bdodson@scms.utmb.edu>
#
# $FreeBSD$
#

PORTNAME=	nab
PORTVERSION=	5.0
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	http://www.scripps.edu/case/ \
		http://siegfried.utmb.edu/bdodson/

MAINTAINER=	bdodson@scms.utmb.edu
COMMENT=	A language for macromolecules

BUILD_DEPENDS=	ucpp:${PORTSDIR}/devel/ucpp
RUN_DEPENDS=	ucpp:${PORTSDIR}/devel/ucpp

ONLY_FOR_ARCHS=	i386

MAKE_ENV+=	NABHOME=${WRKSRC} ARCH= PATH=${WRKSRC}/bin:${PATH} \
		CFLAGS="${CFLAGS}" FFLAGS="${FFLAGS}"

MAN1=		nab.1
SUB_FILES=	pkg-message

BINARIES=	matextract	matmul		teLeap		tss_main \
		matgen		nab		transform	tss_next \
		matmerge	nab2c		tss_init

LIBRARIES=	cifparse.a	libnab.a        libsym.a

INCS=	defreal.h	nab.h		nabcode.h	nabtypes.h

post-extract:
	@${CP} ${FILESDIR}/config.h ${WRKSRC}

post-patch:
	@${RM} -f ${WRKSRC}/examples/circle.c
	@${RM} -f ${WRKSRC}/reslib/conf.lib.orig

pre-install:
	@cd ${WRKSRC}/src && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} beforerealinstall

do-install:
	${MKDIR} ${DATADIR}/bin ${DATADIR}/include ${DATADIR}/lib
	cd ${WRKSRC}/test && ${RM} -f d01.pdb gbrna.pdb.lpdb rembed.out
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && (${TAR} cf - benchmarks examples test peptide suppose | \
		(cd ${DATADIR}; ${TAR} xf -))
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/NAB.pdf ${DOCSDIR}
.endif
	cd ${WRKSRC} && (${TAR} cf - dgdb reslib fd_data leap | \
		(cd ${DATADIR}; ${TAR} xf -))
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}/*
	cd ${DATADIR} && ${LN} -sf ../NDB coords
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${PREFIX}/bin
.for f in ${INCS}
	${INSTALL_DATA} ${WRKSRC}/include/${f} ${PREFIX}/include
	cd ${DATADIR}/include && ${LN} -sf ${PREFIX}/include/${f} .
.endfor
	${INSTALL_DATA} ${WRKSRC}/config.h ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/doc/nab.1 ${MAN1PREFIX}/man/man1
.for f in ${BINARIES}
	cd ${DATADIR}/bin && ${LN} -sf ${PREFIX}/bin/${f} .
.endfor
.for f in ${LIBRARIES}
	${INSTALL_DATA} ${WRKSRC}/lib/${f} ${PREFIX}/lib
	cd ${DATADIR}/lib && ${LN} -sf ${PREFIX}/lib/${f} .
.endfor
.for f in blas.a lapack.a
	${INSTALL_DATA} ${WRKSRC}/lib/${f} ${DATADIR}/lib
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
