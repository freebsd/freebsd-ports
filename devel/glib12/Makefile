# New ports collection makefile for:   glib11-devel
# Version required:		1.1.13
# Date Created:			28 July 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.15 1999/01/21 19:18:20 vanilla Exp $
#

DISTNAME=	glib-1.1.14
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gimp.org/pub/gtk/v1.1/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/v1.1/ \
		http://www.ameth.org/gimp/gtk/v1.1/

MAINTAINER=	vanilla@FreeBSD.ORG

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--includedir=${PREFIX}/include/glib11d

MAN1=		glib-config.1

post-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
