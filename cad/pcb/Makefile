# New ports collection makefile for:	PCB
# Version required:	1.4.0
# Date created:		19 October 1994
# Whom:			mr
#
# $Id: Makefile,v 1.15 1996/11/15 23:30:59 obrien Exp $
#

DISTNAME=	pcb-1.4.0
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.uni-ulm.de/pub/pcb/1.4/

MAINTAINER=	janek@gaja.ipan.lublin.pl

RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_IMAKE=	yes
MAN1=		pcb.1
MANCOMPRESSED=	yes
DOCDIR=		${LOCALBASE}/share/doc/pcb

post-install:
	@${MKDIR}  ${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/README_FILES/* ${DOCDIR}

.include <bsd.port.mk>
