# New ports collection makefile for:	ripperx
# Date created:		2006-12-26
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	ripperx
PORTVERSION=	2.7.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ripperx
DISTNAME=	ripperX-${PORTVERSION}

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	GTK program to rip CD audio tracks and encode them

LIB_DEPENDS=	id3:${PORTSDIR}/audio/id3lib
RUN_DEPENDS=	cdparanoia:${PORTSDIR}/audio/cdparanoia

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12

.include <bsd.port.mk>
