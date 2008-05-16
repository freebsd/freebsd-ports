# New ports collection makefile for:	yudit
# Date created:		October 3, 1998
# Whom:			rch@richard.eu.org
#
# $FreeBSD$
#

PORTNAME=	yudit
PORTVERSION=	2.9.0
PORTREVISION=	1
CATEGORIES=	editors converters print
MASTER_SITES=	http://yudit.org/download/ \
		SUNSITE/apps/editors/X
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-lingual unicode text editor with TTF support

CONFLICTS=	uniconvertor-[0-9]*

USE_XORG=	x11
USE_GNOME=	gnometarget
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LC_ALL=
MAKE_ENV=	LC_ALL=
MAN1=		mytool.1 uniconv.1 uniprint.1
USE_GMAKE=	YES

.include <bsd.port.mk>
