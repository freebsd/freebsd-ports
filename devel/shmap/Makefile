# ex:ts=8
# Ports collection makefile for:	shmap
# Date Created:			Feb 20, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	shmap
PORTVERSION=	0.3.2
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Shared-memory-based hashmaps

LIB_DEPENDS=	mm.12:${PORTSDIR}/devel/mm

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes


.include <bsd.port.mk>
