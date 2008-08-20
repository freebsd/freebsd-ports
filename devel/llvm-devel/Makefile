# New ports collection makefile for:	llvm
# Date created:		20 Nov 2005
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	llvm
DISTVERSION=	2.4.snap${SNAPDATE}
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks
PKGNAMESUFFIX=	-devel

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Low Level Virtual Machine

.if defined(PACKAGE_BUILDING) || defined(MAINTAINER_MODE)
BUILD_DEPENDS=	runtest:${PORTSDIR}/misc/dejagnu
.endif
.if defined(MAINTAINER_MODE)
BUILD_DEPENDS+=	f2c:${PORTSDIR}/lang/f2c
.endif

.if defined(BOOTSTRAP)
SVN_SNAPDATE!=	date -v-1d +%Y-%m-%d
.else
SVN_SNAPDATE=	2008-08-17
.endif

SNAPDATE=	${SVN_SNAPDATE:S/-//g}

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_PERL5_BUILD=yes

.if defined(MAINTAINER_MODE)
CONFIGURE_ARGS+=	--with-f2c=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--enable-optimized
.endif

MAN1=		bugpoint.1 llc.1 lli.1 llvm-ar.1 \
		llvm-as.1 llvm-bcanalyzer.1 llvm-config.1 llvm-db.1 \
		llvm-dis.1 llvm-extract.1 llvm-ld.1 llvm-link.1 llvm-nm.1 \
		llvm-prof.1 llvm-ranlib.1 llvmgcc.1 \
		llvmgxx.1 opt.1 tblgen.1

.if defined(BOOTSTRAP)
FETCH_DEPENDS+=	svn:${PORTSDIR}/devel/subversion

do-fetch:
	${MKDIR} ${WRKDIR}
	svn export http://llvm.org/svn/llvm-project/llvm/trunk ${WRKSRC}
	svn export http://llvm.org/svn/llvm-project/cfe/trunk ${WRKSRC}/tools/clang
	cd ${WRKDIR}; tar cvfy ${DISTDIR}/${DISTNAME}.tar.bz2 ${DISTNAME}
.endif

post-patch:
	${REINPLACE_CMD} -e 's,\(PROJ_docsdir.*:=\).*$$,\1${DOCSDIR},g' \
		${WRKSRC}/Makefile.config.in
	${REINPLACE_CMD} -e 's,\(PROJ_mandir.*:=\).*$$,\1${MANPREFIX}/man,g' \
		${WRKSRC}/Makefile.config.in
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' \
		${WRKSRC}/tools/clang/utils/scan-build

post-build:
	cd ${WRKSRC}/tools/clang; ${GMAKE}

post-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/Release/bin/clang ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/clang/utils/ccc \
	    ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/clang/utils/ccc-analyzer \
	    ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/clang/utils/scan-build \
	    ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/tools/clang/utils/sorttable.js ${DATADIR}
	@${RM} ${PREFIX}/bin/.dir \
	   ${PREFIX}/lib/.dir

.if defined(MAINTAINER_MODE)
regression-test: ${BUILD_COOKIE}
	(cd ${WRKSRC}/test; ${SETENV} ${MAKE_ENV} ${GMAKE} check)
.endif

.include <bsd.port.mk>
