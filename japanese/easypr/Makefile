# New ports collection makefile for:	easypr
# Version required:	0.25
# Date created:		99/10/19
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	print-0.25
PKGNAME=	ja-easypr-0.25
CATEGORIES=	japanese print
MASTER_SITES=	http://www.linet.gr.jp/~mituiwa/

MAINTAINER=	taoka@FreeBSD.org

RUN_DEPENDS=	e2ps:${PORTSDIR}/japanese/e2ps \
		wish4.2jp:${PORTSDIR}/japanese/tk42 \
		psnup:${PORTSDIR}/print/psutils-a4 \
		giftopnm:${PORTSDIR}/graphics/netpbm

do-build:
	${ECHO} '#!${PREFIX}/bin/wish4.2jp' > ${WRKSRC}/easypr
	${CAT} ${WRKSRC}/easypr.in >> ${WRKSRC}/easypr

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/easypr ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/lpr2 ${PREFIX}/bin

.include <bsd.port.mk>
