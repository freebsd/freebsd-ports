# New ports collection makefile for:	geda
# Version required:		19990124
# Date created:			24 Nov 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.7 1999/01/22 21:30:11 nectar Exp $
#

DISTNAME=	gEDA-19990124
PKGNAME=	geda-19990124
CATEGORIES=	cad
MASTER_SITES=	http://www.geda.seul.org/dist/  \
		ftp://ftp.geda.seul.org/pub/geda/dist/ \
		ftp://ftp.infodrom.north.de/pub/unix/gtk-etc/apps/geda/

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=	gtk11d.1:${PORTSDIR}/x11-toolkits/gtk11-devel \
		guile.4:${PORTSDIR}/lang/guile

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS}" 
CONFIGURE_ARGS=	--with-gtk-config=${X11BASE}/bin/gtk11d-config

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
