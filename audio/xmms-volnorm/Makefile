# New ports collection makefile for:	xmms-volnorm
# Date created:				Fri Aug 17 12:17:23 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	volnorm
PORTVERSION=	0.8.1
CATEGORIES=	audio
MASTER_SITES=	http://volnorm.sourceforge.net/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	xmms-

MAINTAINER=	pat@FreeBSD.org

LIB_DEPENDS=	xmms.3:${PORTSDIR}/audio/xmms

USE_X_PREFIX=	yes
USE_GTK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
