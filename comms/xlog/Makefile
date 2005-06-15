# New ports collection makefile for:	xlog
# Date created:		2002-11-05
# Whom:			Patrick Gardella <patrick@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	xlog
PORTVERSION=	1.2.2
CATEGORIES=	comms
MASTER_SITES=	http://pg4i.mattsnetwork.co.uk/download/ \
		http://www.qsl.net/pg4i/download/

MAINTAINER=	matt@mattsnetwork.co.uk
COMMENT=	Amateur Radio logging application

USE_X_PREFIX=	yes
USE_GNOME=	libgnomeprint gtk20
GNU_CONFIGURE=	yes

.if defined(WITH_HAMLIB)
LIB_DEPENDS+=	hamlib:${PORTSDIR}/comms/hamlib
CONFIGURE_ARGS+=	--enable-hamlib
.endif

MAN1=		xlog.1

pre-extract:
.if !defined(WITH_HAMLIB)
	@${ECHO_MSG} "You can enable hamlib support for Xlog by defining WITH_HAMLIB"
.endif

.include <bsd.port.mk>
