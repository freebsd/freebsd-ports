# New ports collection makefile for:	geda
# Version required:		19990124
# Date created:			24 Nov 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.8 1999/02/19 04:28:52 vanilla Exp $
#

DISTNAME=	gEDA-19990327
PKGNAME=	geda-19990327
CATEGORIES=	cad
MASTER_SITES=	http://www.geda.seul.org/dist/  \
		ftp://ftp.geda.seul.org/pub/geda/dist/ \
		ftp://ftp.infodrom.north.de/pub/unix/gtk-etc/apps/geda/

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=	gtk12.1:${PORTSDIR}/x11-toolkits/gtk12 \
		guile.4:${PORTSDIR}/lang/guile

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS}" 
CONFIGURE_ARGS=	--with-gtk-config=${X11BASE}/bin/gtk12-config

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
