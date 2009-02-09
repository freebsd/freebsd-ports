# New ports collection makefile for:    MonoDoc
# Date created:         2004-08-13
# Friday the 13th!
# Whom:                 Christopher Nehren
#
# $FreeBSD$
#   $Id: Makefile,v 1.50 2007/12/13 19:33:57 killfill Exp $
#

PORTNAME=	monodoc
PORTVERSION=	2.0
CATEGORIES=	devel gnome
MASTER_SITES=	ftp://ftp.novell.com/pub/mono/sources/${PORTNAME}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Documentation for Mono and Mono libraries

BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono
RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono

USE_GNOME=	gnomehack gnometarget
USE_ZIP=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--mandir=${PREFIX}/man

MAN1=		mdnormalizer.1 mdvalidator.1 monodocer.1 monodocs2html.1 \
		mdassembler.1 mdcs2ecma.1 mdoc-assemble.1 mdoc-export-html.1 \
		mdoc-export-msxdoc.1 mdoc-update.1 mdoc-validate.1 mdoc.1
MAN5=		mdoc.5

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
