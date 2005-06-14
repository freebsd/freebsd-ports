# New ports collection makefile for:	PCB
# Date created:		19 October 1994
# Whom:			mr
#
# $FreeBSD$
#

PORTNAME=	pcb
PORTVERSION=	20050609
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	X11 interactive printed circuit board layout system

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4
RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-rpath

INFO=		pcb

.if !defined(NOPORTDOCS)
pre-install:
	${INSTALL_DATA} ${WRKSRC}/doc/pcb.info ${PREFIX}/info
.endif

.include <bsd.port.mk>
