# New ports collection makefile for:	umbrello
# Date created:				21 September 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	umbrello
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= uml

MAINTAINER=	demon@FreeBSD.org
COMMENT=	UML Modeller

BUILD_DEPENDS=	autoconf213:${PORTSDIR}/devel/autoconf213 \
		automake14:${PORTSDIR}/devel/automake14

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
