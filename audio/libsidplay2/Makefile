# New ports collection makefile for:   libsidplay
# Date created:        31 October 1996
# Whom:                Stefan Zehl <sec@42.org>
#
# $FreeBSD$
#

PORTNAME=	libsidplay
PORTVERSION=	1.36.40
CATEGORIES=	audio emulators
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sec@42.org

WRKSRC=		${WRKDIR}/${PKGNAME}
#USE_XLIB=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
USE_NEWGCC=	yes

.include <bsd.port.mk>
