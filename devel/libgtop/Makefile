# New ports collection makefile for:	libgtop
# Version required:		0.26.2
# Date Created:			26 Sep 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.6 1998/10/08 15:24:37 vanilla Exp $
#

DISTNAME=	libgtop-0.26.2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.home-of-linux.org/pub/libgtop/0.26.2/

MAINTAINER=	Nakai@technologist.com

LIB_DEPENDS=	glib11.0:${PORTSDIR}/devel/glib

BROKEN=		build
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
