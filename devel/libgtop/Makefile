# New ports collection makefile for:	libgtop
# Version required:		0.99.2
# Date Created:			26 Sep 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.12 1999/01/14 17:00:22 vanilla Exp $
#

DISTNAME=	libgtop-0.99.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME} \
		ftp://ftp.home-of-linux.org/pub/libgtop/0.99.2/
MASTER_SITE_SUBDIR=	libgtop

MAINTAINER=	nacai@iname.com

LIB_DEPENDS=	glib11d.2:${PORTSDIR}/devel/glib11-devel \
		gnome.1:${PORTSDIR}/x11/gnomelibs \
		guile.4:${PORTSDIR}/lang/guile

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls
CONFIGURE_ENV=	GLIB_CONFIG="${LOCALBASE}/bin/glib11d-config"
USE_GMAKE=	yes

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
