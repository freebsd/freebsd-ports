# ex:ts=8
# Ports collection makefile for:	gnump3d
# Date created:			May 27, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gnump3d
PORTVERSION=	0.9.9.9
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_BZIP2=	yes
MAKE_ENV=	CC="${CXX}" CFLAGS="${CXXFLAGS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
ALL_TARGET=	freebsd

MAN1=	mp3d.1 mp3d.conf.1 mp3d-config.1 mp3d-top.1

.include <bsd.port.mk>
