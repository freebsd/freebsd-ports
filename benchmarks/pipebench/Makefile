# ex:ts=8
# New ports collection makefile for:	pipebench
# Date created:			Jan 14, 2003
# Whom:				mich@freebsdcluster.org
#
# $FreeBSD$
#

PORTNAME=	pipebench
PORTVERSION=	0.20
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.habets.pp.se/pub/synscan/

MAINTAINER=	mich@freebsdcluster.org

USE_REINPLACE=  yes

post-patch:
post-patch:
	@${REINPLACE_CMD} -e "s|^CC|#CC|g" \
	-e "s|^CFLAGS|#CFLAGS|g" ${WRKSRC}/Makefile
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pipebench ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pipebench.1 ${PREFIX}/man/man1

MAN1=	pipebench.1
.include <bsd.port.mk>
