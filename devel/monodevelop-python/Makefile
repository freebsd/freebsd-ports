# New ports collection makefile for:	monodevelop-python
# Date created:		2011-09-21
# Whom:			Romain Tartiere <romain@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	monodevelop-python
PORTVERSION=	2.8
CATEGORIES=	devel
MASTER_SITES=	http://download.mono-project.com/sources/${PORTNAME}/

MAINTAINER=	romain@FreeBSD.org
COMMENT=	MonoDevelop Python support

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/monodevelop.pc:${PORTSDIR}/devel/monodevelop
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/monodevelop.pc:${PORTSDIR}/devel/monodevelop

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gtksharp20

post-patch:
	@${REINPLACE_CMD} -e 's|#!/bin/bash|#!/usr/bin/env bash|' \
	    ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$[(]libdir[)]/pkgconfig|$$(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/PyBinding/Makefile

# Restrict to stable (even) versions, indicated by the second component.
PORTSCOUT=	limitw:1,even

.include <bsd.port.mk>
