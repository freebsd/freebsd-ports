# New ports collection makefile for:	SLIB for Gauche
# Date created:			27 October 2003
# Whom:				Kimura Fuyuki <fuyuki@nigredo.org>
#
# $FreeBSD$
#

PORTNAME=	slib
PORTVERSION=	3b3 # Keep this in sync with devel/slib
PORTREVISION=	1
CATEGORIES=	lang scheme
MASTER_SITES=	# empty
PKGNAMESUFFIX=	-gauche
DISTFILES=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SLIB installation for Gauche

BUILD_DEPENDS=	${LOCALBASE}/share/slib/require.scm:${PORTSDIR}/lang/slib \
		gosh:${PORTSDIR}/lang/gauche
RUN_DEPENDS=	${LOCALBASE}/share/slib/require.scm:${PORTSDIR}/lang/slib \
		gosh:${PORTSDIR}/lang/gauche

NO_BUILD=	yes
PLIST_SUB=	VERSION="`gauche-config -V`"

do-install:
	${LOCALBASE}/bin/gosh -uslib -E"require 'new-catalog" -Eexit

.include <bsd.port.mk>
