# ex:ts=8
# Ports collection makefile for:	MathPlanner
# Date created:			Feb 8, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	MathPlanner
PORTVERSION=	3.1.3
CATEGORIES=	editors
MASTER_SITES=	http://koti.mbnet.fi/jarmonik/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A mathematical design and publishing application

USE_QT_VER=	3
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	QTDIR="${QT_PREFIX}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile with gcc 2.95.x"
.endif

.if ${OSVERSION} >= 502126
BROKEN=		"Broken pkg-plist"
.endif

post-patch:
	@${GREP} -lR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e "s|malloc\.h|stdlib.h|"

.include <bsd.port.post.mk>
