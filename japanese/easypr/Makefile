# New ports collection makefile for:	easypr
# Date created:		99/10/19
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	easypr
PORTVERSION=	0.70
CATEGORIES=	japanese print
MASTER_SITES=	http://www.linet.gr.jp/~mituiwa/
DISTNAME=	print-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A control panel for printers (with Japanese messages)

RUN_DEPENDS=	e2ps:${PORTSDIR}/japanese/e2ps \
		wish8.0jp:${PORTSDIR}/japanese/tk80 \
		psnup:${PORTSDIR}/print/psutils-a4 \
		giftopnm:${PORTSDIR}/graphics/netpbm

do-build:
	${ECHO_CMD} '#!${PREFIX}/bin/wish8.0jp' > ${WRKSRC}/easypr
	${CAT} ${WRKSRC}/easypr.in >> ${WRKSRC}/easypr
	cd ${WRKSRC}; ${CC} -o setcap setcap.c

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/easypr ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/lpr2 ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/setcap ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja-easypr
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ja-easypr/README.jp
.endif

.include <bsd.port.mk>
