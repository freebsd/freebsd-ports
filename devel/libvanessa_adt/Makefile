# New ports collection makefile for:	libvanessa_adt
# Date created:		28 April 2001
# Whom:			Konstantinos Konstantinidis <kkonstan@daemon.gr>
#
# $FreeBSD$
#

PORTNAME=	libvanessa_adt
PORTVERSION=	0.0.2
CATEGORIES=	devel
MASTER_SITES=	http://www.vergenet.net/linux/vanessa/download/%SUBDIR%/
MASTER_SITE_SUBDIR=	vanessa_adt/${PORTVERSION}
DISTNAME=	vanessa_adt-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	vanessa_logger.0:${PORTSDIR}/devel/libvanessa_logger

INSTALLS_SHLIB=	YES

USE_LIBTOOL=	YES
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
