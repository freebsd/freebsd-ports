# New ports collection makefile for:   libU77
# Version required:    2.6
# Date Created:                8 October 1998
# Whom:                        Glenn Johnson <gjohnson@nola.srrc.usda.gov>
#
# $FreeBSD$
#

DISTNAME=      libU77-2.6
CATEGORIES=    devel
MASTER_SITES=  http://flo.mech.eng.usyd.edu.au/norris/src/

MAINTAINER=    ports@FreeBSD.org

.include <bsd.port.pre.mk>

pre-build:
	${CP} ${FILESDIR}/makefile.lib ${WRKSRC}/Makefile

MAN3=   access.3f alarm.3f chdir.3f chmod.3f ctime.3f drand.3f dsecnd.3f    \
	dtime.3f etime.3f exit.3f falloc.3f fdate.3f fork.3f free.3f        \
	fstat.3f gerror.3f getarg.3f getcwd.3f getenv.3f getgid.3f          \
	getlog.3f getpid.3f getuid.3f gmtime.3f hostnm.3f iargc.3f idate.3f \
	ierrno.3f irand.3f itime.3f kill.3f len.3f link.3f lnblnk.3f loc.3f \
	lstat.3f ltime.3f malloc.3f mclock.3f perror.3f qsort.3f rand.3f    \
	rename.3f second.3f seterr.3f signal.3f sleep.3f stat.3f symlnk.3f  \
	system.3f time.3f unlink.3f wait.3f wclock.3f

post-install:
	${LDCONFIG} -m ${PREFIX}/lib
	if [ "${PORTOBJFORMAT}" = "aout" ]; then \
		${LN} -sf libU77.so.1.0 ${PREFIX}/lib/libU77.so; \
	fi
	${INSTALL_MAN} ${WRKSRC}/man/*.3f ${PREFIX}/man/man3

.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/libU77
	${INSTALL_DATA} ${WRKSRC}/doc/manual.ps ${PREFIX}/share/doc/libU77
.endif

.include <bsd.port.post.mk>
