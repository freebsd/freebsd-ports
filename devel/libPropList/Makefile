# New ports collection makefile for:	libPropList
# Date Created:				6 December 1998
# Whom:					Glenn Johnson
#
# $FreeBSD$
#

PORTNAME=	libproplist
PORTVERSION=	0.10.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_TUCOWS}
MASTER_SITE_SUBDIR=	gnome/dev
DISTNAME=	libPropList-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Property library for gnome and Window Maker

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e "s,mkdir rmdir,mkdir mkstemp rmdir," \
		${WRKSRC}/configure

.include <bsd.port.mk>
