# ex:ts=8
# Ports collection makefile for:	log4c
# Date created:			Jul 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	log4c
PORTVERSION=	1.0.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.cimai.com/opensource/log4c/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Logging for C Library

LIB_DEPENDS=	expat.4:${PORTSDIR}/textproc/expat2

USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
