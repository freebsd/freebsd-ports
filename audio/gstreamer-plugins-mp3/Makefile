# New ports collection makefile for:	gstreamer-plugins-mp3
# Date created:		2007-06-07
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gstreamer-plugins
PORTVERSION=	0.10.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	# empty
PKGNAMESUFFIX=	-mp3
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Gstreamer Plugins Mp3 decoder meta-port

NO_BUILD=	yes
WANT_GSTREAMER=	yes
OPTIONS=	MAD "Use MAD Mp3" On \
		FLUENDO "Use Fluendo Mp3" Off

.include <bsd.port.pre.mk>

.if !defined(WITH_MAD) && !defined(WITH_FLUENDO)
WITH_MAD=	yes
.endif

.if defined(WITH_MAD)
USE_GSTREAMER+=	mad
.endif

.if defined(WITH_FLUENDO)
USE_GSTREAMER+=	fluendo-mp3
.endif

do-install:

.include <bsd.port.post.mk>
