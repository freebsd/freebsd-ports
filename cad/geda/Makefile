# New ports collection makefile for:	geda
# Version required:		19981117
# Date created:			24 Nov 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.1.1.1 1998/12/06 14:11:53 vanilla Exp $
#

DISTNAME=	gEDA-19981117
PKGNAME=	geda-19981117
CATEGORIES=	cad
MASTER_SITES=	http://www.geda.seul.org/dist/  \
		ftp://ftp.geda.seul.org/pub/geda/dist/

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=	gtk.1:${PORTSDIR}/x11-toolkits/gtk \
		guile.4:${PORTSDIR}/lang/guile

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS}"

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
