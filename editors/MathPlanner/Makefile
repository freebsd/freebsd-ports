# ex:ts=8
# Ports collection makefile for:	MathPlanner
# Date created:			Feb 8, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	MathPlanner
PORTVERSION=	3.1.2
CATEGORIES=	editors
MASTER_SITES=	http://koti.mbnet.fi/jarmonik/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A mathematical design and publishing application

USE_REINPLACE=	yes
USE_QT_VER=	3
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	QTDIR="${X11BASE}"

post-patch:
	@${GREP} -lR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e "s|malloc\.h|stdlib.h|"

.include <bsd.port.mk>
