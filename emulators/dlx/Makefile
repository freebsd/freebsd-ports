# ex:ts=8
# Ports collection makefile for:  dlx
# Date created:			  Mon Dec 23, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	dlx
PORTVERSION=	2.0
CATEGORIES=	emulators
MASTER_SITES=	ftp://foofoo.stanford.edu/pub/max/pub/hennessy-patterson.software/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Assembler for Hennessy and Patterson's DLX architecture

.include <bsd.port.pre.mk>

.if ${ARCH} != i386
BROKEN=		will not build on ${ARCH}
.endif

.if ${OSVERSION} > 500000
BROKEN=		does not build on -current
.endif

MAN1=		dlxcc.1

do-configure:
	cd ${WRKSRC}/gcc ; ./config.gcc dlx

do-build:
	cd ${WRKSRC}/dlxsim ; make install
	cd ${WRKSRC}/gcc ; make prefix=${PREFIX} INSTALLDIR=${PREFIX}/bin

do-install:
	@cd ${WRKSRC}/gcc ; make prefix=${PREFIX} INSTALLDIR=${PREFIX}/bin install
	@${STRIP_CMD} ${PREFIX}/bin/dlxcc ${PREFIX}/bin/dlx-gcc-cc1 \
		${PREFIX}/bin/dlx-gcc-cpp
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dlxsim ${PREFIX}/bin
	@cd ${WRKSRC}/man ; ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/dlxsim/doc/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
