# New ports collection makefile for:	PCB
# Version required:	1.5.5 beta
# Date created:		19 October 1994
# Whom:			mr
#
# $Id: Makefile,v 1.16 1997/05/30 20:38:25 max Exp $
#

DISTNAME=	pcb-1.5.5.BETA
PKGNAME=	pcb-1.5.5
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.uni-ulm.de/pub/pcb/1.5/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jseger@FreeBSD.org

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		texindex:${PORTSDIR}/print/teTeX

USE_IMAKE=	yes
MAN1=		pcb.1
MANCOMPRESSED=	yes

pre-install:
	@${CP} ${WRKSRC}/doc/pcb.man ${WRKSRC}/src

.include <bsd.port.mk>
