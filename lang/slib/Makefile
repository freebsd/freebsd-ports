# New ports collection makefile for:   slib
# Version required:    2c0
# Date created:        01 April 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.2 1998/10/26 13:15:54 vanilla Exp $
#

DISTNAME=	slib2c0
PKGNAME=	slib-2c0
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.gnome.org/pub/GNOME/extra-src/

MAINTAINER=	nacai@iname.com

BUILD_DEPENDS=	scheme48:${PORTSDIR}/lang/scheme48

WRKSRC=		${WRKDIR}/slib

ALL_TARGET=	slib48
INSTALL_TARGET=	install48

post-install:
	${MKDIR} ${PREFIX}/share/slib
	${INSTALL_DATA} ${WRKSRC}/*.scm ${PREFIX}/share/slib

.include <bsd.port.mk>
