# New ports collection makefile for:	logjam2
# Date created:				30 Oct 2002
# Whom:					michael johnson <ahze@rgv.net>
#
# $FreeBSD$
#

PORTNAME=	logjam2
PORTVERSION=	4.1.0
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://logjam.danga.com/download/
DISTNAME=	logjam-${PORTVERSION}

MAINTAINER=	mike.patterson@unb.ca
COMMENT=	A GTK interface to user journals on www.livejournal.com

LIB_DEPENDS=	curl.2:${PORTSDIR}/ftp/curl \
		gtkspell.0:${PORTSDIR}/textproc/gtkspell2

MAN1=		logjam.1

USE_GMAKE=	yes
USE_GNOME=	libxml2
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --program-transform-name="s/$$//"

.include <bsd.port.mk>
