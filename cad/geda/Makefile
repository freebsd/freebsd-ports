# New ports collection makefile for:	geda
# Version required:		19981213
# Date created:			24 Nov 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.5 1998/12/27 20:49:40 vanilla Exp $
#

DISTNAME=	gEDA-19981213
PKGNAME=	geda-19981213
CATEGORIES=	cad
MASTER_SITES=	http://www.geda.seul.org/dist/  \
		ftp://ftp.geda.seul.org/pub/geda/dist/ \
		ftp://ftp.infodrom.north.de/pub/unix/gtk-etc/apps/geda/

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=	gtk.1:${PORTSDIR}/x11-toolkits/gtk \
		guile.4:${PORTSDIR}/lang/guile

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS}" 
CONFIGURE_ARGS=	--with-gtk-config=${X11BASE}/bin/gtk10-config

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
