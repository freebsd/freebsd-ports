# New ports collection makefile for:   sidplay
# Version required:    1.36.31
# Date created:        31 October 1996
# Whom:                Stefan Zehl <sec@42.org>
#
# $Id: Makefile,v 1.3 1998/11/28 09:07:10 asami Exp $
#

DISTNAME=	sidplay-1_36_31
PKGNAME=        sidplay-1.36.31
CATEGORIES=	audio emulators
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sec@42.org

BUILD_DEPENDS=	makedepend:${PORTSDIR}/x11/XFree86

GNU_CONFIGURE=	YES

USE_GMAKE=	YES

WRKSRC=		${WRKDIR}/${PKGNAME}

post-install:
	strip ${PREFIX}/bin/sidplay ${PREFIX}/bin/sid2wav ${PREFIX}/bin/sidcon

.include <bsd.port.mk>
