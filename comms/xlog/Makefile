# New ports collection makefile for:	xlog
# Date created:		2002-11-05
# Whom:			Patrick Gardella <patrick@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	xlog
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://www.qsl.net/pg4i/download/

MAINTAINER=	patrick@FreeBSD.org
COMMENT=	An Amateur Radio station logging application

BROKEN=		"Does not compile"

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes

MAN1=		xlog.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha" && ${OSVERSION} < 500000
BROKEN=		"Does not compile on alpha 4.x"
.endif

.if defined(WITH_HAMLIB)
LIB_DEPENDS=	hamlib:${PORTSDIR}/comms/hamlib
CONFIGURE_ARGS+=	--enable-hamlib
PLIST_SUB+=	HAMLIB=""
USE_GNOME=	pkgconfig
.endif

pre-extract:
.if !defined(WITH_HAMLIB)
	@${ECHO_MSG} "You can enable hamlib support for Xlog by defining WITH_HAMLIB"
.endif

.include <bsd.port.post.mk>
