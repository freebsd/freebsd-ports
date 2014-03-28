# Created by: michael johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	pnetmark
PORTVERSION=	0.0.6
PORTREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	${PNET_MASTER_SITES}
MASTER_SITE_SUBDIR=	${PNET_MASTER_SITE_SUBDIR}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Benchmarking tool for Common Language Runtime (CLR)

DEPRECATED=	PNET dependency decommissioned Dec 2012 
EXPIRATION_DATE=2014-05-01

BUILD_DEPENDS=	cscc:${PORTSDIR}/lang/pnet-base \
		csunit:${PORTSDIR}/lang/pnetlib
RUN_DEPENDS=	cscc:${PORTSDIR}/lang/pnet-base \
		csunit:${PORTSDIR}/lang/pnetlib

GNU_CONFIGURE=	yes
USES=		gmake
STRIP=		# Nothing to Strip
PORTDOCS=	pm_faq.html
PNET_STRAP_BIN=	pnetmark \
		linpack \
		scimark2

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/pnet/Makefile.pnet"
.include <bsd.port.pre.mk>

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/pnetmark.exe ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/linpack/linpack.exe ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/scimark2/scimark2.exe ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for docfile in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
