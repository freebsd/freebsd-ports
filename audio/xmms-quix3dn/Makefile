# New ports collection makefile for:	xmms-quix3dn
# Date created:        			23 December 2000
# Whom:					alex
#
# $FreeBSD$
#

PORTNAME=	xmms-quix3dn
PORTVERSION=	4.4.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	alex
DISTNAME=	quix3dn-${PORTVERSION}-freebsd

MAINTAINER=	alex@FreeBSD.org
COMMENT=	A 3D-sound effect plugin for XMMS

RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

USE_X_PREFIX=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_FILES=	lib/xmms/Effect/libquix3dn.so

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
LIB_DEPENDS+=	c.4:${PORTSDIR}/misc/compat4x
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/libquix3dn.so ${PREFIX}/lib/xmms/Effect/

.include <bsd.port.post.mk>
