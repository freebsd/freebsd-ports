# New ports collection makefile for:	agbrowser
# Date created:				7 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	agbrowser
PORTVERSION=	0.96
CATEGORIES=	audio
MASTER_SITES=	http://www.geocities.com/uallloveme/OSS/AGBrowser/

MAINTAINER=	lioux@FreeBSD.org

# USE_AUTO{CONF,MAKE} breaks it
BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf \
		automake:${PORTSDIR}/devel/automake

USE_KDELIBS_VER=2
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
