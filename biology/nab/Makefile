# New ports collection Makefile for: nab
# Date created:         Sept. 10, 2000
# Whom:                 M. L. Dodson <mldodson@houston.rr.com>
#
# $FreeBSD$
#

PORTNAME=	nab
PORTVERSION=	5.1.2
CATEGORIES=	biology
MASTER_SITES=	http://www.scripps.edu/mb/case/

MAINTAINER=	mldodson@houston.rr.com
COMMENT=	A language for macromolecules

BUILD_DEPENDS=	ucpp:${PORTSDIR}/devel/ucpp
RUN_DEPENDS=	ucpp:${PORTSDIR}/devel/ucpp

ONLY_FOR_ARCHS=	i386

MAKE_ENV+=	NABHOME=${WRKSRC} ARCH= PATH=${WRKSRC}/bin:${PATH} \
		CFLAGS="${CFLAGS}" OCFLAGS="${CFLAGS}" FFLAGS="${FFLAGS}"

MAN1=		nab.1
SUB_FILES=	pkg-message

BINARIES=	matmerge nab2c teLeap tss_main \
		matextract matmul transform tss_next \
		matgen nab tss_init

LIBRARIES=	cifparse.a libnab.a libsym.a

INCS=		defreal.h nab.h nabcode.h nabtypes.h

do-configure:
	@${CP} ${FILESDIR}/config.h ${WRKSRC}

post-patch:
	@${RM} -f ${WRKSRC}/examples/circle.c
	@${RM} -f ${WRKSRC}/reslib/conf.lib.orig
	@${RM} -f ${WRKSRC}/examples/program_7.nab.orig

do-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install
	@cd ${WRKSRC}/test && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test
	@cd ${WRKSRC}/nss  && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test

build-general-version:
	@cd ${WRKSRC}/src && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} beforerealinstall

do-install: build-general-version
	${MKDIR} ${DATADIR}/bin ${DATADIR}/include ${DATADIR}/lib
	cd ${WRKSRC}/test && ${RM} -f d01.pdb gbrna.pdb.lpdb rembed.out
	cd ${WRKSRC}/examples && ${RM} -f gcg10.pdb.save
	cd ${WRKSRC}/leap/parm && ${RM} -f leap.log
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && (${TAR} cf - benchmarks examples test | \
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
.for f in blas.a lapack.a f2c.a
	${INSTALL_DATA} ${WRKSRC}/lib/${f} ${DATADIR}/lib
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
