# New ports collection makefile for:	logjam
# Date created:		13 Aug 01
# Whom:			alanp@unixpower.org
#
# $FreeBSD$
#

PORTNAME=	logjam
PORTVERSION=	3.0.4
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://logjam.danga.com/download/

MAINTAINER=	alanp@unixpower.org
COMMENT=	A GTK interface to user journals on www.livejournal.com

LIB_DEPENDS=	curl.2:${PORTSDIR}/ftp/curl

MAN1=		logjam.1

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk12

.include <bsd.port.mk>
