# New ports collection makefile for:	metabar
# Date created:				Fri Feb 25 15:44:58 CET 2005
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	metabar
PORTVERSION=	0.8
PORTREVISION=	10
CATEGORIES=	deskutils kde
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sidebar plugin for Konqueror

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_KDEBASE_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g'	${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
