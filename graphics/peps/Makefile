# New ports collection makefile for:	peps
# Date created:				5 July 2001
# Whom:					petef@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	peps
PORTVERSION=	1.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.whizkidtech.net/peps/

MAINTAINER=	petef@FreeBSD.org

RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript-gnu \
		pnmtopng:${PORTSDIR}/graphics/netpbm

post-patch:
	@${PERL} -pi -e 's!cc -O3!${CC} ${CFLAGS}!' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/peps ${PREFIX}/bin

.include <bsd.port.mk>
