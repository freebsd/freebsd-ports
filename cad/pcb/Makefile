# New ports collection makefile for:	PCB
# Version required:	1.7
# Date created:		19 October 1994
# Whom:			mr
#
# $FreeBSD$
#

DISTNAME=	pcb-1.7
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.netlab.is.tsukuba.ac.jp/pub/linux/Plamo/Plamo-current/contrib/Electronic/sources/

MAINTAINER=	jseger@FreeBSD.org

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		latex:${PORTSDIR}/print/teTeX

USE_IMAKE=	yes
MAN1=		pcb.1
MANCOMPRESSED=	yes

pre-install:
	@${CP} ${WRKSRC}/doc/pcb.man ${WRKSRC}/src

.include <bsd.port.mk>
