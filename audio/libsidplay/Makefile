# New ports collection makefile for:   sidplay
# Version required:    1.36.10
# Date created:        31 October 1996
# Whom:                Stefan Zehl <sec@42.org>
#
# $Id: Makefile,v 1.1.1.1 1998/07/26 08:14:02 dburr Exp $
#

DISTNAME=	sidplay-13625
PKGNAME=        sidplay-1.36.25
CATEGORIES=	audio emulators
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sec@42.org

GNU_CONFIGURE=	YES

USE_GMAKE=	YES

WRKSRC=		${WRKDIR}/${PKGNAME}

post-install:
	strip ${PREFIX}/bin/sidplay ${PREFIX}/bin/sid2wav ${PREFIX}/bin/sidcon

.include <bsd.port.mk>
