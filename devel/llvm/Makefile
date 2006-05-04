# New ports collection makefile for:	llvm
# Date created:		20 Nov 2005
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	llvm
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	devel lang
MASTER_SITES=	http://llvm.cs.uiuc.edu/releases/${PORTVERSION}/

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Low Level Virtual Machine

BROKEN=		Does not build

GNU_CONFIGURE=	yes
USE_BISON=	yes
USE_GMAKE=	yes
MAKE_ENV=	ENABLE_OPTIMIZED=1 # strips binaries

WRKSRC=		${WRKDIR}/llvm

MAN1=		analyze.1 bugpoint.1 gccas.1 gccld.1 llc.1 lli.1 llvm-ar.1 \
		llvm-as.1 llvm-bcanalyzer.1 llvm-db.1 llvm-dis.1 \
		llvm-extract.1 llvm-ld.1 llvm-link.1 llvm-nm.1 llvm-prof.1 \
		llvm-ranlib.1 llvmc.1 llvmgcc.1 llvmgxx.1 opt.1 stkrc.1

post-patch:
	${REINPLACE_CMD} -e 's,\(OPTIONAL_DIRS.*\)examples,\1,g' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's,\(PROJ_docsdir.*:=\).*$$,\1${DOCSDIR},g' \
		${WRKSRC}/Makefile.config.in
	${RM} -rf ${WRKSRC}/projects/sample

.include <bsd.port.mk>
