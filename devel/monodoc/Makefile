# New ports collection makefile for:    MonoDoc
# Date created:         2004-08-13
# Friday the 13th!
# Whom:                 Christopher Nehren
#
# $FreeBSD$
#   $Id: Makefile,v 1.40 2007/02/07 15:44:59 killfill Exp $
#

PORTNAME=	monodoc
PORTVERSION=	1.2.3
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

MAN1=		mdnormalizer.1 mdvalidator.1 monodocer.1 monodocs2html.1 \
		mdassembler.1 mdcs2ecma.1

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
