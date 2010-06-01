# New ports collection makefile for:	monodevelop-vala
# Date created:		2009-06-30
# Whom:			Romain Tartiere <romain@blogreen.org>
#
# $FreeBSD$
#

PORTNAME=	monodevelop-vala
PORTVERSION=	2.2
CATEGORIES=	devel
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/${PORTNAME}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Vala language support for Monodevelop

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/monodevelop.pc:${PORTSDIR}/devel/monodevelop
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/monodevelop.pc:${PORTSDIR}/devel/monodevelop \
		exctags:${PORTSDIR}/devel/ctags \
		valac:${PORTSDIR}/lang/vala

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
PLIST_FILES=	lib/monodevelop/AddIns/BackendBindings/MonoDevelop.ValaBinding.dll

# Restrict to stable (even) versions, indicated by the second component.
PORTSCOUT=	limitw:1,even

.include <bsd.port.mk>
