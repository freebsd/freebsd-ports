# New ports collection makefile for:	PCB
# Date created:		19 October 1994
# Whom:			mr
#
# $FreeBSD$
#

PORTNAME=	pcb
PORTVERSION=	1.7.3
CATEGORIES=	cad
MASTER_SITES=	http://bach.ece.jhu.edu/~haceaton/pcb/
DISTNAME=	${PORTNAME}-wip
EXTRACT_SUFX=	.tgz

MAINTAINER=	gagnon__s@videotron.ca
COMMENT=	X11 interactive printed circuit board layout system

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		latex:${PORTSDIR}/print/teTeX

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_IMAKE=	yes

MAN1=		pcb.1

pre-install:
	-${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${SETENV} PREFIX=${PREFIX} make install.info &&\
	${INSTALL_DATA} index.html pcb.html pcb.ps refcard.ps ${DOCSDIR}

post-install:
	install-info --section="Utilities" \
	--entry="* PCB: (pcb).	Interactive printed circuit board layout system for X11" \
	${PREFIX}/info/pcb.info ${PREFIX}/info/dir

.include <bsd.port.mk>
