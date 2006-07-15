# Ports collection makefile for:	vstr
# Date created:		11 February 2004
# Whom:			Robert Schlotterbeck <robert@rs.tarrant.tx.us>
#
# $FreeBSD$
#

PORTNAME=	vstr
PORTVERSION=	1.0.15
CATEGORIES=	devel
MASTER_SITES=	http://www.and.org/vstr/1.0.15/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose string library for C

BROKEN=		fails to patch

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig
INSTALLS_SHLIB=	yes

MAN3=		vstr.3 vstr_const.3

.include <bsd.port.mk>
