# Created by: Kimura Fuyuki <fuyuki@nigredo.org>
# $FreeBSD$

PORTNAME=	slib
PORTVERSION=	3b3 # Keep this in sync with devel/slib
PORTREVISION=	1
CATEGORIES=	lang scheme
MASTER_SITES=	# empty
PKGNAMESUFFIX=	-gauche
DISTFILES=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SLIB installation for Gauche

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-12-22

BROKEN=		does not build

BUILD_DEPENDS=	${LOCALBASE}/share/slib/require.scm:${PORTSDIR}/lang/slib \
		gosh:${PORTSDIR}/lang/gauche
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_BUILD=	yes
PLIST_SUB=	VERSION="`gauche-config -V`"

NO_STAGE=	yes
do-install:
	${LOCALBASE}/bin/gosh -uslib -E"require 'new-catalog" -Eexit

.include <bsd.port.mk>
