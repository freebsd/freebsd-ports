# New ports collection makefile for:	libsidplay2
# Date created:				6 October 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libsidplay2
PORTVERSION=	2.0.7
CATEGORIES=	audio emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sidplay2
DISTNAME=	${PORTNAME:S/2//}-${PORTVERSION}-5
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	resid.2:${PORTSDIR}/audio/resid

WRKSRC=		${WRKDIR}/${PORTNAME:S/2//}-${PORTVERSION}

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes

.include <bsd.port.mk>
