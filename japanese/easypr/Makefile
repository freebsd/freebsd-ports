# New ports collection makefile for:	easypr
# Date created:		99/10/19
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	easypr
PORTVERSION=	0.60
CATEGORIES=	japanese print
MASTER_SITES=	http://plamo.linet.gr.jp/~mituiwa/
DISTNAME=	print-${PORTVERSION}

MAINTAINER=	taoka@FreeBSD.org

RUN_DEPENDS=	e2ps:${PORTSDIR}/japanese/e2ps \
		wish4.2jp:${PORTSDIR}/japanese/tk42 \
		psnup:${PORTSDIR}/print/psutils-a4 \
		giftopnm:${PORTSDIR}/graphics/netpbm

do-build:
	${ECHO} '#!${PREFIX}/bin/wish4.2jp' > ${WRKSRC}/easypr
	${CAT} ${WRKSRC}/easypr.in >> ${WRKSRC}/easypr
	cd ${WRKSRC}; ${CC} -o setcap setcap.c

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/easypr ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/lpr2 ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/setcap ${PREFIX}/bin

.include <bsd.port.mk>
