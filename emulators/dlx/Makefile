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
MASTER_SITES=	http://max.stanford.edu/max/pub/hennessy-patterson.software/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org

.if ${MACHINE_ARCH} == alpha
BROKEN=		will not build on alpha
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

.include <bsd.port.mk>
