# New ports collection makefile for:   sidplay
# Date created:        31 October 1996
# Whom:                Stefan Zehl <sec@42.org>
#
# $FreeBSD$
#

PORTNAME=	sidplay
PORTVERSION=	1.36.38
CATEGORIES=	audio emulators
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/
DISTNAME=	lib${PORTNAME}-${PORTVERSION:S/./_/g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sec@42.org

WRKSRC=		${WRKDIR}/lib${PKGNAME}
USE_XLIB=	yes
USE_LIBTOOL=	yes
INSTALL_SHLIBS=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
