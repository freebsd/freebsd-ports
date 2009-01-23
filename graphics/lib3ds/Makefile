# New ports collection makefile for:	lib3ds
# Date Created:				18 January 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lib3ds
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library for handling 3DS (3D Studio) files

USE_ZIP=	yes
USE_LDCONFIG=	yes
USE_GL=		glut
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		3dsdump.1 lib3ds-config.1

.include <bsd.port.mk>
