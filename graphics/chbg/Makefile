# New ports collection makefile for:	chbg
# Date created:		10 Dec 1999
# Whom:			Peter Jones <p@dancris.com>
#
# $FreeBSD$
#

PORTNAME=	chbg
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.idata.sk/~ondrej/sw/
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	p@dancris.com

USE_X_PREFIX=	yes
USE_GNOMECTRL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		chbg.1

.include <bsd.port.mk>
