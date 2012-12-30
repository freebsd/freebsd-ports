# ex:ts=8
# Ports collection makefile for:	divxcalc
# Date created:			Mar 21, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	divxcalc
PORTVERSION=	0.6
PORTREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	http://www.axllent.org/uploads/files/divxcalc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DivX Calculator

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_XORG=	x11 ice xext
USE_BZIP2=	yes
USE_QT_VER=	3
USE_GMAKE=	yes
USE_AUTOTOOLS=	automake:env autoconf:env
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/divxcalc

pre-configure:
	@cd ${WRKSRC} && ${GMAKE} -f admin/Makefile.common

.include <bsd.port.mk>
