# New ports collection makefile for:    MonoDoc
# Date created:         2004-08-13
# Friday the 13th!
# Whom:                 Christopher Nehren
#
# $FreeBSD$
#   $Id: Makefile,v 1.32 2006/01/03 03:35:28 tmclau02 Exp $
#

PORTNAME=	monodoc
PORTVERSION=	1.1.11
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

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
