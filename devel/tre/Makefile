# New ports collection makefile for:	tre
# Date created:		2006-07-31
# Whom:			Joseph Koshy <jkoshy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tre
PORTVERSION=	0.7.4
CATEGORIES=	devel
MASTER_SITES=	http://laurikari.net/tre/

MAINTAINER=	jkoshy@FreeBSD.org
COMMENT=	A lightweight, robust, efficient regexp matching library

USE_LDCONFIG=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--program-prefix="" --enable-system-abi
USE_AUTOTOOLS=	libtool:15

OPTIONS=	AGREP	"Build agrep(1)"	on

.include <bsd.port.pre.mk>

.if defined(WITH_AGREP)
MAN1=		agrep.1
PLIST_SUB+=	AGREP=""
CONFLICTS=	glimpse-4.*
.else
PLIST_SUB+=	AGREP="@comment "
CONFIGURE_ARGS+=	--disable-agrep
.endif

.include <bsd.port.post.mk>
