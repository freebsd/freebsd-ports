# ex:ts=8
# Ports collection makefile for:	shmap
# Date Created:			Feb 20, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	shmap
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-devel/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shared-memory-based hashmaps

LIB_DEPENDS=	mm.14:${PORTSDIR}/devel/mm

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes

.include <bsd.port.mk>
