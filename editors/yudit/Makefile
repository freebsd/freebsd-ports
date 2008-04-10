# New ports collection makefile for:	yudit
# Date created:		October 3, 1998
# Whom:			rch@richard.eu.org
#
# $FreeBSD$
#

PORTNAME=	yudit
PORTVERSION=	2.8.1
PORTREVISION=	2
CATEGORIES=	editors converters print
MASTER_SITES=	http://yudit.org/download/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/editors/X
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-lingual unicode text editor with TTF support

USE_GETTEXT=	yes
USE_XORG=	x11
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LDFLAGS="-L${X11BASE}/lib" \
		LC_ALL=
GNU_CONFIGURE=	YES
MAKE_ENV=	LC_ALL=
MAN1=		mytool.1 uniconv.1 uniprint.1
USE_GMAKE=	YES

.include <bsd.port.mk>
