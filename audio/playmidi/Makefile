# New ports collection makefile for:    playmidi
# Version required:     2.3
# Date created:         27 Feb 1995
# Whom:                 ache
#
# $FreeBSD$
#

DISTNAME=       playmidi-2.3
CATEGORIES=     audio
MASTER_SITES=   ${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/players

MAINTAINER=     ache@FreeBSD.org

IS_INTERACTIVE= YES	# asks what devices you want to support
HAS_CONFIGURE=  YES
CONFIGURE_SCRIPT=       Configure
CONFIGURE_ENV=  PREFIX=${PREFIX}
INSTALL_TARGET= install.lame install.man
MAN1=		playmidi.1

.include <bsd.port.mk>
