# ports collection makefile for: Clipboard
# Date created:      28 Jun 1997
# Whom:              Ruslan Shevchenko <ruslan@shevchenko.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	offix-trash
PORTVERSION=	2.4
PORTREVISION=	1
CATEGORIES=	deskutils offix
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	desktop_managers/OffiX
DISTNAME=	Trash-${PORTVERSION}

MAINTAINER=	ruslan@shevchenko.kiev.ua
COMMENT=	Trash from OffiX

LIB_DEPENDS=	Dnd++.1:${PORTSDIR}/x11/libdnd

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X_PREFIX=	YES

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile (bad C++ code)"
.endif

.include <bsd.port.post.mk>
