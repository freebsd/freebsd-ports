# New ports collection makefile for:	llvm
# Date created:		20 Nov 2005
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	llvm
PORTVERSION=	2.3
PORTREVISION=	2
CATEGORIES=	devel lang
MASTER_SITES=	http://llvm.org/releases/${PORTVERSION}/
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Low Level Virtual Machine

.if defined(PACKAGE_BUILDING) || defined(MAINTAINER_MODE)
BUILD_DEPENDS=	runtest:${PORTSDIR}/misc/dejagnu
.endif
.if defined(MAINTAINER_MODE)
BUILD_DEPENDS+=	f2c:${PORTSDIR}/lang/f2c
.endif

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes

.if defined(MAINTAINER_MODE)
CONFIGURE_ARGS+=	--with-f2c=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--enable-optimized
.endif

.if defined(NOPORTDOCS)
DOCSRCDIR=	
.else
DOCSRCDIR=	docs
.endif

MAN1=		bugpoint.1 llc.1 lli.1 llvm-ar.1 \
		llvm-as.1 llvm-bcanalyzer.1 llvm-config.1 llvm-db.1 \
		llvm-dis.1 llvm-extract.1 llvm-ld.1 llvm-link.1 llvm-nm.1 \
		llvm-prof.1 llvm-ranlib.1 llvmgcc.1 \
		llvmgxx.1 opt.1 stkrc.1 tblgen.1

post-patch:
	${REINPLACE_CMD} -e 's|\(PROJ_docsdir.*:=\).*$$|\1${DOCSDIR}|g' \
	    ${WRKSRC}/Makefile.config.in
	${REINPLACE_CMD} -e 's|\(PROJ_mandir.*:=\).*$$|\1${MANPREFIX}/man|g' \
	    ${WRKSRC}/Makefile.config.in
	${REINPLACE_CMD} -e 's|%%DOCSRCDIR%%|${DOCSRCDIR}|' \
	    ${WRKSRC}/Makefile

post-build:
	cd ${WRKSRC}/docs/CommandGuide && \
	    ${GMAKE} man

post-install:
	cd ${WRKSRC}/docs/CommandGuide && \
	    ${INSTALL_MAN} ${MAN1} ${MANPREFIX}/man/man1/
	@${RM} ${PREFIX}/bin/.dir \
	   ${PREFIX}/lib/.dir

regression-test: build
	(cd ${WRKSRC}/test; ${SETENV} ${MAKE_ENV} ${GMAKE} check)

.include <bsd.port.mk>
