# New ports collection makefile for:	xlog
# Date created:		2002-11-05
# Whom:			Patrick Gardella <patrick@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	xlog
PORTVERSION=	1.5
CATEGORIES=	comms hamradio
MASTER_SITES=	http://pg4i.chronos.org.uk/download/ \
		http://www.qsl.net/pg4i/download/

MAINTAINER=	matt@chronos.org.uk
COMMENT=	Amateur Radio logging application

USE_GETTEXT=	yes
USE_GNOME=	libgnomeprint gnomelibs gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mime-update \
		--mandir=${PREFIX}/man

LIB_DEPENDS+=	hamlib:${PORTSDIR}/comms/hamlib

MAN1=		xlog.1

.if defined (WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
WITHNLS=	"@comment "
.else
WITHNLS=	""
.endif

PLIST_SUB+=	WITHNLS=${WITHNLS}

.include <bsd.port.mk>
