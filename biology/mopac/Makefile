# New ports collection makefile for:	mopac
# Date created:				1997-04-23
# Whom:					Ryo MIYAMOTO <rmiya@cc.hirosaki-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	mopac
PORTVERSION=	7.02
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	http://www.ccl.net/cca/software/SOURCES/FORTRAN/mopac7_sources/
DISTNAME=	mopac7
DISTFILES=	mopac7.tar.Z  mopac7-man.tar.Z

PATCH_SITES=	http://www.ccl.net/cca/software/LINUX/mopac7/old-version-95.06.21/
PATCHFILES=	mopac7-linux.diff.Z
PATCH_DIST_STRIP=	-p1

MAINTAINER=	rmiya@cc.hirosaki-u.ac.jp
COMMENT=	Semi-empirical (MNDO, etc.) molecular orbital calculation

USE_GMAKE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		"Does not install on FreeBSD >= 5.x"
.endif

.if ${OSVERSION} >= 400005
BUILD_DEPENDS=	ftn77:${PORTSDIR}/lang/f77
MAKE_ARGS+=	FC=ftn77
.else
MAKE_ARGS+=	FC=f77
.endif
MAKE_ARGS+=	FFLAGS="${FFLAGS} -w" CFLAGS="${CFLAGS} -I${PREFIX}/include"
.if ${MACHINE_ARCH} == "i386"
FFLAGS+=	-malign-double
.endif

post-patch:
	${CP}  ${WRKDIR}/${DISTNAME}/esp.rof  ${WRKDIR}/${DISTNAME}/esp.f

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/MOPAC7 ${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/rmopac ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mopac
	${MKDIR} ${PREFIX}/share/examples/mopac
	${MKDIR} ${PREFIX}/share/mopac/test
	${INSTALL_DATA} ${FILESDIR}/h2o.dat  ${PREFIX}/share/examples/mopac
	${INSTALL_SCRIPT} ${WRKDIR}/mopac7/test.csh ${PREFIX}/share/mopac/test
	${INSTALL_DATA} ${WRKDIR}/mopac7/test_* ${PREFIX}/share/mopac/test
	${INSTALL_DATA} ${WRKDIR}/mopac7-man/mopac.tex ${PREFIX}/share/doc/mopac
	${INSTALL_DATA} ${WRKDIR}/mopac7-man/mopac.dvi ${PREFIX}/share/doc/mopac
.endif

.include <bsd.port.post.mk>
