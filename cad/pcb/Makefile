# New ports collection makefile for:	PCB
# Date created:		19 October 1994
# Whom:			mr
#
# $FreeBSD$
#

PORTNAME=	pcb
PORTVERSION=	20030815
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	X11 interactive printed circuit board layout system

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		latex:${PORTSDIR}/print/teTeX \
		wish:${PORTSDIR}/x11-toolkits/tk84

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

GNU_CONFIGURE=	yes

INFO=		pcb

post-install:
	install-info --section="Utilities" \
	--entry="* PCB: (pcb).	Interactive printed circuit board layout system for X11" \
	${PREFIX}/info/pcb.info ${PREFIX}/info/dir

.include <bsd.port.mk>
