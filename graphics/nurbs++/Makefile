# New ports collection makefile for:	nurbs++
# Date created:				14 May 2000
# Whom:					R Joseph Wright <rjoseph@mammalia.org>
#
# $FreeBSD$
#

PORTNAME=	nurbs++
PORTVERSION=	3.0.11
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	libnurbs

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++ library for representing curves or surfaces

USE_REINPLACE=	yes
USE_LIBTOOL_VER=13
CONFIGURE_ARGS=	--program-transform-name="s/x/x/"
INSTALLS_SHLIB=	yes

MAN1=	nurbs++-config.1

pre-patch:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/nurbs/nurbs.cpp ${WRKSRC}/nurbs/nurbsS.cpp

.include <bsd.port.mk>
