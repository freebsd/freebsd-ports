# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	monodevelop-vala
PORTVERSION=	2.8
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://download.mono-project.com/sources/${PORTNAME}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Vala language support for Monodevelop

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-11-18

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/monodevelop.pc:${PORTSDIR}/devel/monodevelop
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/monodevelop.pc:${PORTSDIR}/devel/monodevelop \
		exctags:${PORTSDIR}/devel/ctags \
		valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	afrodite-0.12:${PORTSDIR}/devel/vtg

BROKEN=		does not build

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
PLIST_FILES=	lib/monodevelop/AddIns/BackendBindings/MonoDevelop.ValaBinding.dll \
		lib/monodevelop/AddIns/BackendBindings/MonoDevelop.ValaBinding.dll.config

# Restrict to stable (even) versions, indicated by the second component.
PORTSCOUT=	limitw:1,even

NO_STAGE=	yes
.include <bsd.port.mk>
