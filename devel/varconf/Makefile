# New ports collection makefile for:	varconf
# Date created:				29 March 2001
# Whom:					Oliver Lehmann <lehmann@ans-netz.de>
#
# $FreeBSD$
#

PORTNAME=	varconf
PORTVERSION=	0.5.4
CATEGORIES=	devel
MASTER_SITES=	ftp://victor.worldforge.org/%SUBDIR%/ \
		http://purple.worldforge.org/wf/downloads/libs/varconf/ \
		http://grimicus.dyndns.org:8080/%SUBDIR%/ \
		ftp://ftp.fr.gnome.org/%SUBDIR%/
MASTER_SITE_SUBDIR= pub/worldforge/libs/varconf

MAINTAINER=	lehmann@ans-netz.de

LIB_DEPENDS=	sigc.1:${PORTSDIR}/devel/libsigc++

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include <bsd.port.mk>
