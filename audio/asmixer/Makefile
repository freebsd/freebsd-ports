# New ports collection makefile for:	asmixer
# Date created:		2 January 2003
# Whom:			mtm@identd.net
#
# $FreeBSD$
#

PORTNAME=	asmixer
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	audio afterstep
MASTER_SITES=	http://www.tigr.net/afterstep/download/asmixer/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A mixer control for X and specifically the AfterStep Window Manager

MAN1=		${PORTNAME}.1x
PLIST_FILES=	bin/asmixer

USE_XORG=	xpm x11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-xpm \
		--with-xpm-includes=${LOCALBASE} \
		--with-xpm-library=${LOCALBASE}

post-install:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.man \
	    ${MAN1PREFIX}/man/man1/${PORTNAME}.1x

.include <bsd.port.mk>
