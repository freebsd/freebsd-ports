# New ports collection makefile for:   jmode
# Date created:        26 February 2002
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jmode
PORTVERSION=	0.6.7
PORTREVISION=	2
CATEGORIES=	japanese
MASTER_SITES=	http://downloads.sourceforge.jp/anthy/5467/

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT?=	XIM server for Anthy input method

LIB_DEPENDS?=	anthy.0:${PORTSDIR}/japanese/anthy

USE_X_PREFIX=	yes
USE_GNOME=	gnometarget gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
