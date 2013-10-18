# Created by: Romain Tartiere <romain@FreeBSD.org>
# $FreeBSD$

PORTNAME=	monodevelop-python
PORTVERSION=	2.8.8.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://download.mono-project.com/sources/${PORTNAME}/

MAINTAINER=	romain@FreeBSD.org
COMMENT=	MonoDevelop Python support

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-11-18

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/monodevelop.pc:${PORTSDIR}/devel/monodevelop
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/monodevelop.pc:${PORTSDIR}/devel/monodevelop

BROKEN=		does not build

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gtksharp20

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|#!/bin/bash|#!/usr/bin/env bash|' \
	    ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$[(]libdir[)]/pkgconfig|$$(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/PyBinding/Makefile

# Restrict to stable (even) versions, indicated by the second component.
PORTSCOUT=	limitw:1,even

.include <bsd.port.mk>
