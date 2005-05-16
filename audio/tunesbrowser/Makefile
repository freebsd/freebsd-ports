# New ports collection makefile for:	tunesbrowser
# Date created:		2004-07-27
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	tunesbrowser
PORTVERSION=	0.3.0
CATEGORIES=	audio
MASTER_SITES=	http://craz.net/programs/itunes/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple iTunes-like music player

LIB_DEPENDS=	opendaap.0:${PORTSDIR}/devel/libopendaap

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget libglade2
WANT_GNOME=	yes
USE_GSTREAMER=	mad
GNU_CONFIGURE=	yes

MAN1=		tunesbrowser.1

OPTIONS=	FAAD "Enable AAC/MP4 Audio output" Off

.include <bsd.port.pre.mk>

.if defined(WITH_FAAD)
USE_GSTREAMER+=	faad
.endif

.if ${HAVE_GNOME:Mlibgnome}!=""
PKGNAMESUFFIX=	-gnome
USE_GNOME+=	libgnome
.else
CONFIGURE_ARGS+=	--disable-gnome
.endif

.include <bsd.port.post.mk>
