# New ports collection makefile for:	PCB
# Version required:	1.4.0
# Date created:		19 October 1994
# Whom:			mr
#
# $Id: Makefile,v 1.11 1996/03/25 08:30:42 asami Exp $
#

DISTNAME=	pcb-1.4.0
CATEGORIES+=	cad
MASTER_SITES=	ftp://ftp.uni-ulm.de/pub/pcb/1.4/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	janek@gaja.ipan.lublin.pl

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		bison:${PORTSDIR}/devel/bison \
		${LOCALBASE}/bin/flex:${PORTSDIR}/devel/flex

USE_IMAKE=	yes

.include <bsd.port.mk>
