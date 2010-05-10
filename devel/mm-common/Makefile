# New ports collection makefile for:   mm-common
# Date Created:			27 Aug 2009
# Whom:				Koop Mast<kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/mm-common/Makefile,v 1.11 2010/05/03 00:54:20 avl Exp $
#

PORTNAME=	mm-common
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Common build infrastructure for the GNOME C++ binding libraries

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl

USE_GNOME=	gnomehack
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		mm-common-prepare.1

.include <bsd.port.mk>
