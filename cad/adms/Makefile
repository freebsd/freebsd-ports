# New ports collection makefile for:	adms
# Date created:		2006-07-29
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	adms
PORTVERSION=	2.3.0
PORTREVISION=	0
CATEGORIES=	cad
MASTER_SITES=	SF/mot-${PORTNAME}/${PORTNAME}-source/${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A model generator for SPICE simulators

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GNOME=	glib20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_PKGCONFIG=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		admsXml.1

.include <bsd.port.mk>
