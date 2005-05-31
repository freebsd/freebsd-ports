# ex:ts=8
# Ports collection makefile for:	libshbuf
# Date created:			May 6, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libshbuf
PORTVERSION=	0.0.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for Shared Buffer IPC

USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
