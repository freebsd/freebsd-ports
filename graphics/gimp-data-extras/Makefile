# New ports collection makefile for:	gimp-data-extras
# Date created:		2008-02-23
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gimp-data-extras
PORTVERSION=	2.0.2
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/%SUBDIR%/ \
		http://gimp.mirrors.hoobly.com/%SUBDIR%/ \
		http://ftp.gwdg.de/pub/misc/grafik/gimp/%SUBDIR%/ \
		ftp://ftp.fh-heilbronn.de/mirrors/ftp.gimp.org/%SUBDIR%/ \
		ftp://ftp.insync.net/pub/mirrors/ftp.gimp.org/%SUBDIR%/ \
		http://www.mirrorservice.org/sites/ftp.gimp.org/pub/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/%SUBDIR%,}
MASTER_SITE_SUBDIR=	gimp/extras/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of additional brushes and patterns files for GIMP

LIB_DEPENDS=	gimp-2.0.0:${PORTSDIR}/graphics/gimp-app

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
