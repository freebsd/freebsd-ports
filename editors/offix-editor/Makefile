# ports collection makefile for: Editor
# Date created:      28 Jun 1997
# Whom:              Ruslan Shevchenko <ruslan@shevchenko.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	offix-editor
PORTVERSION=	2.4
PORTREVISION=	1
CATEGORIES=	editors offix
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	desktop_managers/OffiX
DISTNAME=	Editor-${PORTVERSION}

MAINTAINER=	ruslan@shevchenko.kiev.ua
COMMENT=	Editor from OffiX

LIB_DEPENDS=	Dnd.1:${PORTSDIR}/x11/libdnd

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X_PREFIX=	YES
USE_XPM=	YES
MAN1=		editor.1

.include <bsd.port.mk>
