# Created by: alex
# $FreeBSD$

PORTNAME=	xmms-quix3dn
PORTVERSION=	4.4.1
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	alex
DISTNAME=	quix3dn-${PORTVERSION}-freebsd

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D-sound effect plugin for XMMS

LIB_DEPENDS=	c.4:${PORTSDIR}/misc/compat4x
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

NO_STAGE=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_FILES=	lib/xmms/Effect/libquix3dn.so
ONLY_FOR_ARCHS=	i386

do-install:
	${INSTALL_DATA} ${WRKSRC}/libquix3dn.so ${PREFIX}/lib/xmms/Effect/

.include <bsd.port.mk>
