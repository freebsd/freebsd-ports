# New ports collection makefile for:	libwmf
# Version required:	0.1.10
# Date Created:		22 May 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	libwmf-0.1.14
CATEGORIES=	graphics
MASTER_SITES=	http://www.csn.ul.ie/~caolan/publink/libwmf/

MAINTAINER=	cpiazza@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		ttf.3:${PORTSDIR}/print/freetype

WRKSRC=		${WRKDIR}/libwmf

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ttf=${LOCALBASE}

.include <bsd.port.mk>
