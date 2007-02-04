# New ports collection makefile for:    MonoDoc
# Date created:         2004-08-13
# Friday the 13th!
# Whom:                 Christopher Nehren
#
# $FreeBSD$
#   $Id: Makefile,v 1.38 2006/11/23 00:42:17 killfill Exp $
#

PORTNAME=	monodoc
PORTVERSION=	1.2.1
CATEGORIES=	devel gnome
MASTER_SITES=	http://www.go-mono.com/sources/${PORTNAME}/

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	Documentation for Mono and Mono libraries

BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono
RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono

USE_GNOME=	gnomehack gnometarget
USE_ZIP=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		mdnormalizer.1 mdvalidator.1 monodocer.1 monodocs2html.1

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
