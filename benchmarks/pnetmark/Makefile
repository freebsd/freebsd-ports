# New ports collection makefile for:	pnetmark
# Date created:		2004-03-19
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	pnetmark
PORTVERSION=	0.0.6
CATEGORIES=	benchmarks
MASTER_SITES=	${PNET_MASTER_SITES}
MASTER_SITE_SUBDIR=	${PNET_MASTER_SITE_SUBDIR}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Benchmarking tool for Common Language Runtime (CLR)

BUILD_DEPENDS=	cscc:${PORTSDIR}/lang/pnet-base \
		csunit:${PORTSDIR}/lang/pnetlib
RUN_DEPENDS=	cscc:${PORTSDIR}/lang/pnet-base \
		csunit:${PORTSDIR}/lang/pnetlib

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
STRIP=		# Nothing to Strip
PORTDOCS=	pm_faq.html
PNET_STRAP_BIN=	pnetmark \
		linpack \
		scimark2

.include "${.CURDIR}/../../lang/pnet/Makefile.pnet"
.include <bsd.port.pre.mk>

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/pnetmark.exe ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/linpack/linpack.exe ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/scimark2/scimark2.exe ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docfile in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
