# New ports collection makefile for: xmms-infopipe
# Date created:        14 July 2003
# Whom:                mig
#
# $FreeBSD$
#

PORTNAME=      xmms-infopipe
PORTVERSION=   1.3
CATEGORIES=    audio
MASTER_SITES=  http://www.beastwithin.org/users/wwwwolf/code/xmms/
MASTER_SITE_SUBDIR=    ${PORTNAME}

MAINTAINER=    mig@mig-29.net
COMMENT=       Create a named pipe to retrive xmms info about currently playing song

RUN_DEPENDS=    xmms-config:${PORTSDIR}/multimedia/xmms

USE_X_PREFIX=   yes
USE_GNOME=     gtk12
GNU_CONFIGURE=  yes

.include <bsd.port.mk>
