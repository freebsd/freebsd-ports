# New ports collection makefile for:	gqmpeg
# Date Created:		28 Oct 1998
# Whom:			Vanilla Pooh Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gqmpeg
PORTVERSION=	0.9.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lyngbol@candid.dk

LIB_DEPENDS=	gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf
RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123

USE_X_PREFIX=	yes
USE_IMLIB=	yes
USE_LIBTOOL=	yes

MAN1=		gqmpeg.1

.include <bsd.port.mk>
