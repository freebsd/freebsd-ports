# New ports collection makefile for:	PCB
# Date created:		19 October 1994
# Whom:			mr
#
# $FreeBSD$
#

PORTNAME=	pcb
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.riken.go.jp/pub/Linux/plamo/Plamo-1.4.x/contrib/Electronic/sources/ \
		ftp://sunsite.tus.ac.jp/pub/archives/linux/jp-linux/plamo/Plamo-1.4.x/contrib/Electronic/sources/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	X11 interactive printed circuit board layout system

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		latex:${PORTSDIR}/print/teTeX

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
