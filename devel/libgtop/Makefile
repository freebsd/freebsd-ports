# New ports collection makefile for:	libgtop
# Version required:		0.99.0
# Date Created:			26 Sep 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.8 1998/11/17 15:28:08 vanilla Exp $
#

DISTNAME=	libgtop-0.99.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.jimpick.com/pub/mirrors/gnome/sources/ \
		ftp://ftp.gnome.org/pub/GNOME/sources/
#		ftp://ftp.home-of-linux.org/pub/libgtop/0.26.2/

MAINTAINER=	Nakai@technologist.com

LIB_DEPENDS=	glib11d.1:${PORTSDIR}/devel/glib11-devel \
		gnome.0:${PORTSDIR}/x11/gnomelibs \
		guile.4:${PORTSDIR}/lang/guile

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls
CONFIGURE_ENV=	GLIB_CONFIG="${LOCALBASE}/bin/glib11d-config"
USE_GMAKE=	yes

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
