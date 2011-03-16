# ex:ts=8
# Ports collection makefile for:	MathPlanner
# Date created:			Feb 8, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	MathPlanner
PORTVERSION=	3.1.3
PORTREVISION=	6
CATEGORIES=	editors
MASTER_SITES=	http://koti.mbnet.fi/jarmonik/ \
		http://fresh.t-systems-sfr.com/unix/src/privat2/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A mathematical design and publishing application

DEPRECATED=     Upstream says project is canceled and no more distfiles can be found
EXPIRATION_DATE=        2011-05-01

USE_QT_VER=	3
GNU_CONFIGURE=	yes

QTCPPFLAGS+=	${PTHREAD_CFLAGS}
QTCFGLIBS+=	${PTHREAD_LIBS}

post-patch:
	@${GREP} -lR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e "s|malloc\.h|stdlib.h|"

.include <bsd.port.mk>
