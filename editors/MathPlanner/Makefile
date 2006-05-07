# ex:ts=8
# Ports collection makefile for:	MathPlanner
# Date created:			Feb 8, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	MathPlanner
PORTVERSION=	3.1.3
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://koti.mbnet.fi/jarmonik/ \
		http://fresh.t-systems-sfr.com/unix/src/privat2/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A mathematical design and publishing application

USE_QT_VER=	3
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	QTDIR="${QT_PREFIX}"

QTCPPFLAGS+=	${PTHREAD_CFLAGS}
QTCFGLIBS+=	${PTHREAD_LIBS}

post-patch:
	@${GREP} -lR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e "s|malloc\.h|stdlib.h|"

.include <bsd.port.mk>
