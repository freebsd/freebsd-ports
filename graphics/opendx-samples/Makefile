# New ports collection makefile for:	opendx-samples
# Date created:		06 Oct 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
# Updates:              Randall Hopper <rhh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	opendx-samples
PORTVERSION=	4.4.0
CATEGORIES=	graphics math
MASTER_SITES=	http://opendx.npaci.edu/source/
DISTNAME=	dxsamples-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Example files for IBM's OpenDX

BUILD_DEPENDS=	dx:${PORTSDIR}/graphics/opendx
RUN_DEPENDS=	dx:${PORTSDIR}/graphics/opendx

BROKEN=		Changes permissions on installed file usr/local/dx/java/server/nets

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	SHELL=/bin/sh
USE_GMAKE=	yes

.if !defined(WITHOUT_JAVA)
USE_JAVA=	yes
JAVA_VERSION=	1.3+
PLIST_SUB+=	JAVA=""
.else
CONFIGURE_ARGS+=	--without-javadx
PLIST_SUB+=	JAVA="@comment "
.endif

.include <bsd.port.mk>
