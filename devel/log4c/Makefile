# ex:ts=8
# Ports collection makefile for:	log4c
# Date created:			Jul 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	log4c
PORTVERSION=	1.0.6
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.cimai.com/opensource/log4c/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	expat.4:${PORTSDIR}/textproc/expat2

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
