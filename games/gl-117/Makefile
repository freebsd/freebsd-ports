# ex:ts=8
# Ports collection makefile for:	gl-117
# Date created:			Aug 8, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gl-117
PORTVERSION=	1.3.2
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/GL-117%20Source
DISTVERSIONSUFFIX=	-src

MAINTAINER=	erik@smluc.org
COMMENT=	An OpenGL & SDL action flight simulator

USE_GL=		glut
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-opengl-dir=${LOCALBASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.include <bsd.port.mk>
