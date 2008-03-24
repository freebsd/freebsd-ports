# New ports collection makefile for:	llvm
# Date created:		20 Nov 2005
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	llvm
PORTVERSION=	2.2
CATEGORIES=	devel lang
MASTER_SITES=	http://llvm.org/releases/${PORTVERSION}/

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Low Level Virtual Machine

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USE_GCC=	3.3+

CONFIGURE_FLAGS+=	--enable-optimized

MAN1=		bugpoint.1 llc.1 lli.1 llvm-ar.1 \
		llvm-as.1 llvm-bcanalyzer.1 llvm-config.1 llvm-db.1 \
		llvm-dis.1 llvm-extract.1 llvm-ld.1 llvm-link.1 llvm-nm.1 \
		llvm-prof.1 llvm-ranlib.1 llvm-upgrade.1 \
		llvm2cpp.1 llvmc.1 llvmgcc.1 \
		llvmgxx.1 opt.1 stkrc.1 tblgen.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64" && ${OSVERSION} >= 700042
BROKEN=		does not build on sparc64
.endif

.if ${PERL_LEVEL} < 500800
BROKEN=		does not compile with perl ${PERL_VERSION}
.endif

post-patch:
	${REINPLACE_CMD} -e 's,\(PROJ_docsdir.*:=\).*$$,\1${DOCSDIR},g' \
		${WRKSRC}/Makefile.config.in
	${REINPLACE_CMD} -e 's,\(PROJ_mandir.*:=\).*$$,\1${MANPREFIX}/man,g' \
		${WRKSRC}/Makefile.config.in

post-install:
	@${RM} ${PREFIX}/bin/.dir \
	    ${PREFIX}/etc/llvm/.dir \
	    ${PREFIX}/lib/.dir

.include <bsd.port.post.mk>
