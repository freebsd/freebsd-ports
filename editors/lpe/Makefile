# New ports collection makefile for:	lpe
# Date created:		12 April 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lpe
PORTVERSION=	1.2.4
CATEGORIES=	editors
MASTER_SITES=	http://cdsmith.twu.net/lpe/

MAINTAINER=	cpiazza@FreeBSD.org

LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang \
		intl.1:${PORTSDIR}/devel/gettext

USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	LDFLAGS="-L${PREFIX}/lib -L${LOCALBASE}/lib" \
		CPPFLAGS="-I${PREFIX}/include -I${LOCALBASE}/include" \
		LIBS="-ltermcap"
CONFIGURE_ARGS=	--includedir=${LOCALBASE}/include

MAN1=	lpe.1

.include <bsd.port.mk>
