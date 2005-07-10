# New ports collection makefile for:    MonoDoc
# Date created:         2004-08-13
# Friday the 13th!
# Whom:                 Christopher Nehren
#
# $Id: Makefile,v 1.20 2005/06/17 05:45:49 tmclau02 Exp $
# $FreeBSD$
#

PORTNAME=	monodoc
PORTVERSION=	1.0.7
CATEGORIES=	devel gnome
MASTER_SITES=	http://www.go-mono.com/sources/${PORTNAME}/

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	Documentation for Mono and Mono libraries

BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono
RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono

USE_GNOME=	gnomehack gnometarget
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
