# New ports collection makefile for:	orbitcpp
# Date created:		30 August 2001
# Whom:	      	  Thomas Hentschel <thomas at hentschel dot net>
#
# $FreeBSD$
#

PORTNAME=	orbitcpp
PORTVERSION=	1.3.9
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ bindings for ORBit, a CORBA 2.2-compliant ORB

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomehack lthack orbit2
USE_INC_LIBTOOL_VER=	13
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|^\(SUBDIRS =.*\)test\(.*\)|\1\2|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
