# New ports collection makefile for:	present
# Date created:		2005-06-13
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/present/Makefile,v 1.8 2006/01/31 22:17:59 ahze Exp $
#

PORTNAME=	present
PORTVERSION=	0.0.3
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.0

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A library for reading Microsoft PowerPoint(tm) documents

LIB_DEPENDS=	goffice-1.2:${PORTSDIR}/devel/goffice

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:15
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
USE_GNOME=	gnomehack intlhack gnometarget ltverhack

.include <bsd.port.mk>
