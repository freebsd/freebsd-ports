# ports collection makefile for:	gliv
# Date created:				16 March 2001
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	gliv
PORTVERSION=	1.0b7
CATEGORIES=	graphics
MASTER_SITES=	http://gliv.tuxfamily.org/
DISTNAME=	GLiv-1.0beta7

MAINTAINER=	ishmael27@home.com

LIB_DEPENDS=	Imlib2.1:${PORTSDIR}/graphics/imlib2 \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_MESA=	yes
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib -lgnugetopt" \
		CPPFLAGS="-I${LOCALBASE}/include"

MAN1=		GLiv.1

.include <bsd.port.mk>
