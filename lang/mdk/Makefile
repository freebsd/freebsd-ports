# ex:ts=8
# New ports collection makefile for:  mdk
# Date created:			Apr 1, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mdk
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	lang gnome
MASTER_SITES=	${MASTER_SITE_GNU:S/$/:gnu/} \
		${MASTER_SITE_SOURCEFORGE:S/$/:sf/}
MASTER_SITE_SUBDIR=	${PORTNAME}/v${PORTVERSION}/:gnu \
			${PORTNAME}/:sf
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:gnu \
		${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:sf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of utilities for developing programs using MIX and MIXAL

LIB_DEPENDS=	guile.15:${PORTSDIR}/lang/guile

USE_X_PREFIX=	yes
USE_GNOME=	gnometarget intlhack libglade2
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

INFO=		mdk

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
