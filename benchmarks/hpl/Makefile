# New ports collection makefile for:	physfs
# Date Created:		22 February 2003
# Whom:			Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hpl
PORTVERSION=	1.0a
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.netlib.org/benchmark/hpl/ \
		ftp://ftp.hipecs.hokudai.ac.jp/netlib/benchmark/hpl/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	High Performance Computing Linpack Benchmark

.if !defined(WITH_LAM)
BUILD_DEPENDS=	${LOCALBASE}/mpich/bin/mpicc:${PORTSDIR}/net/mpich
.else
BUILD_DEPENDS=	${LOCALBASE}/bin/lamd:${PORTSDIR}/net/lam
CC=		${LOCALBASE}/bin/mpicc
FC=		${LOCALBASE}/bin/mpicc
.endif

RUN_DEPENDS=	${BUILD_DEPENDS}

.if defined(WITH_BLAS)
LIB_DEPENDS+=	blas.1:${PORTSDIR}/math/blas
.else
LIB_DEPENDS+=	cblas.1:${PORTSDIR}/math/atlas
.endif

INSTALLS_SHLIB=	yes
HPL_ARCH?=	FreeBSD_PIV_CBLAS
ALL_TARGET=	arch=${HPL_ARCH}
MAN3=		HPL_abort.3 HPL_all_reduce.3 HPL_barrier.3 HPL_bcast.3 \
		HPL_binit.3 HPL_broadcast.3 HPL_bwait.3 HPL_copyL.3 \
		HPL_daxpy.3 HPL_dcopy.3 HPL_dgemm.3 HPL_dgemv.3 HPL_dger.3 \
		HPL_dlacpy.3 HPL_dlamch.3 HPL_dlange.3 HPL_dlaprnt.3 \
		HPL_dlaswp00N.3 HPL_dlaswp01N.3 HPL_dlaswp01T.3 HPL_dlaswp02N.3 \
		HPL_dlaswp03N.3 HPL_dlaswp03T.3 HPL_dlaswp04N.3 HPL_dlaswp04T.3 \
		HPL_dlaswp05N.3 HPL_dlaswp05T.3 HPL_dlaswp06N.3 HPL_dlaswp06T.3 \
		HPL_dlaswp10N.3 HPL_dlatcpy.3 HPL_dlocmax.3 HPL_dlocswpN.3 \
		HPL_dlocswpT.3 HPL_dmatgen.3 HPL_dscal.3 HPL_dswap.3 HPL_dtrsm.3 \
		HPL_dtrsv.3 HPL_equil.3 HPL_fprintf.3 HPL_grid_exit.3 \
		HPL_grid_info.3 HPL_grid_init.3 HPL_idamax.3 HPL_indxg2l.3 \
		HPL_indxg2lp.3 HPL_indxg2p.3 HPL_indxl2g.3 HPL_infog2l.3 \
		HPL_jumpit.3 HPL_ladd.3 HPL_lmul.3 HPL_logsort.3 HPL_max.3 \
		HPL_min.3 HPL_numroc.3 HPL_numrocI.3 HPL_pabort.3 HPL_packL.3 \
		HPL_pddriver.3 HPL_pdfact.3 HPL_pdgesv.3 HPL_pdgesv0.3 \
		HPL_pdgesvK1.3 HPL_pdgesvK2.3 HPL_pdinfo.3 HPL_pdlamch.3 \
		HPL_pdlange.3 HPL_pdlaprnt.3 HPL_pdlaswp00N.3 HPL_pdlaswp00T.3 \
		HPL_pdlaswp01N.3 HPL_pdlaswp01T.3 HPL_pdmatgen.3 HPL_pdmxswp.3 \
		HPL_pdpancrN.3 HPL_pdpancrT.3 HPL_pdpanel_disp.3 \
		HPL_pdpanel_free.3 HPL_pdpanel_init.3 HPL_pdpanel_new.3 \
		HPL_pdpanllN.3 HPL_pdpanllT.3 HPL_pdpanrlN.3 HPL_pdpanrlT.3 \
		HPL_pdrpancrN.3 HPL_pdrpancrT.3 HPL_pdrpanllN.3 HPL_pdrpanllT.3 \
		HPL_pdrpanrlN.3 HPL_pdrpanrlT.3 HPL_pdtest.3 HPL_pdtrsv.3 \
		HPL_pdupdateNN.3 HPL_pdupdateNT.3 HPL_pdupdateTN.3 \
		HPL_pdupdateTT.3 HPL_perm.3 HPL_pipid.3 HPL_plindx0.3 \
		HPL_plindx1.3 HPL_plindx10.3 HPL_pnum.3 HPL_ptimer.3 \
		HPL_ptimer_cputime.3 HPL_ptimer_walltime.3 HPL_pwarn.3 \
		HPL_rand.3 HPL_recv.3 HPL_reduce.3 HPL_rollN.3 HPL_rollT.3 \
		HPL_sdrv.3 HPL_send.3 HPL_setran.3 HPL_spreadN.3 HPL_spreadT.3 \
		HPL_sum.3 HPL_timer.3 HPL_timer_cputime.3 HPL_timer_walltime.3 \
		HPL_warn.3 HPL_xjumpm.3

post-patch:
	@${REINPLACE_CMD} -e 's|^TOPdir[ ]*=.*$$|TOPdir = ${WRKSRC}| ; \
		s|^MPdir[ ]*=.*$$|MPdir = ${LOCALBASE}/mpich| ; \
		s|^LAdir[ ]*=.*$$|LAdir = ${LOCALBASE}/lib| ; \
		s|^CC[ ]*=.*$$|CC = ${CC}| ; \
		s|^CCFLAGS[ ]*=.*$$|CCFLAGS = $$\(HPL_DEFS\) ${CFLAGS} -fomit-frame-pointer -funroll-loops| ; \
		s|^LINKER[ ]*=.*$$|LINKER = ${FC}| ; \
		s|^ARCHIVER[ ]*=.*$$|ARCHIVER = ${AR}| ; \
		s|ARCH[ )]|_&|g' \
		${WRKSRC}/setup/Make.${HPL_ARCH}

.if defined(WITH_LAM)
	@${REINPLACE_CMD} -e 's|^MPdir[ ]*=.*$$|#&| ; s|^MPinc[ ]*=.*$$|#&| ; \
		s|^MPlib[ ]*=.*$$|MPlib = /usr/lib/libg2c.a|' \
		${WRKSRC}/setup/Make.${HPL_ARCH}
.else
	@${REINPLACE_CMD} -e 's|^MPdir[ ]*=.*$$|MPdir = ${LOCALBASE}/mpich|' \
		${WRKSRC}/setup/Make.${HPL_ARCH}
.endif

.if defined(WITH_BLAS)
	@${REINPLACE_CMD} -e 's|^HPL_OPTS[ ]*=.*$$|HPL_OPTS =| ; \
		s|^LAlib[ ]*=.*$$|LAlib = $$\(LAdir\)/libblas.a|' \
		${WRKSRC}/setup/Make.${HPL_ARCH}
.endif

	@${REINPLACE_CMD} -e 's|HPL\.dat|${PREFIX}/etc/${PORTNAME}/&|' \
		${WRKSRC}/testing/ptest/HPL_pdinfo.c

	@${CP} ${WRKSRC}/setup/Make.${HPL_ARCH} ${WRKSRC}/

do-install:
	${MKDIR} ${PREFIX}/etc/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${HPL_ARCH}/xhpl ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/bin/${HPL_ARCH}/HPL.dat ${PREFIX}/etc/${PORTNAME}/
.for man in ${MAN3}
	${INSTALL_MAN} ${WRKSRC}/man/man3/${man} ${MANPREFIX}/man/man3/
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in BUGS COPYRIGHT HISTORY README TODO TUNING
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
