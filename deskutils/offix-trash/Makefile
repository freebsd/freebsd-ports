# ports collection makefile for: Clipboard
# Version required:  2.4
# Date created:      28 Jun 1997
# Whom:              Ruslan Shevchenko <ruslan@shevchenko.kiev.ua>
#
# $Id: Makefile,v 1.2 1998/08/05 09:31:34 asami Exp $
#

DISTNAME=	Trash-2.4
PKGNAME=	offix-trash-2.4
CATEGORIES=	deskutils offix
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	desktop_managers/OffiX

MAINTAINER=	ruslan@shevchenko.kiev.ua

LIB_DEPENDS=	Dnd++\\.1\\.:${PORTSDIR}/x11/libdnd

GNU_CONFIGURE=	YES
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}"
USE_GMAKE=	YES
USE_X_PREFIX=	YES

.include <bsd.port.mk>
