# ex:ts=8
# Ports collection makefile for:  dlx
# Version required:     	  2.0
# Date created:			  Mon Dec 23, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $Id: Makefile,v 1.2 1997/01/25 18:08:40 obrien Exp $
#

DISTNAME=	dlx
PKGNAME=	dlx-2.0
CATEGORIES=	emulators
MASTER_SITES=	ftp://max.stanford.edu/pub/hennessy-patterson.software/   \
		ftp://ftp.cs.keio.ac.jp/pub/arch/hennessy-patterson.software/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=     obrien@FreeBSD.org

MAN1=		dlxcc.1

do-configure:
	cd ${WRKSRC}/gcc ; config.gcc dlx

do-build:
	cd ${WRKSRC}/dlxsim ; make install
	cd ${WRKSRC}/gcc ; make prefix=${PREFIX} INSTALLDIR=${PREFIX}/bin

do-install:
	@cd ${WRKSRC}/gcc ; make prefix=${PREFIX} INSTALLDIR=${PREFIX}/bin install
	@strip ${PREFIX}/bin/dlxcc ${PREFIX}/bin/dlx-gcc-cc1 \
		${PREFIX}/bin/dlx-gcc-cpp
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dlxsim ${PREFIX}/bin
	@cd ${WRKSRC}/man ; ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/dlx
	@${INSTALL_DATA} ${WRKSRC}/dlxsim/doc/* ${PREFIX}/share/doc/dlx
.endif

.include <bsd.port.mk>
