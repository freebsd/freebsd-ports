# New ports collection makefile for:   sphinxbase
# Date created:        8 Jan 2008
# Whom:                r.neese
#
# $FreeBSD$
#

PORTNAME=	sphinxbase
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	audio accessibility
MASTER_SITES=	SF/cmusphinx/${PORTNAME}/${PORTVERSION}

MAINTAINER=	r.neese@gmail.com
COMMENT=	CMU SPhinx Speech recognition system base

USE_LDCONFIG=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
USE_GMAKE=	yes
USE_GNOME=	gnomehack
USE_AUTOTOOLS=	libtool:22

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAKE_ENV=	MKDIR="${MKDIR}" \
		OSVERSION=${OSVERSION}

.include <bsd.port.mk>
