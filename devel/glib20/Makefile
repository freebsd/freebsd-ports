# New ports collection makefile for:   glib12
# Version required:		1.2.0
# Date Created:			28 July 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.17 1999/02/17 18:12:08 vanilla Exp $
#

DISTNAME=	glib-1.2.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gimp.org/pub/gtk/v1.2/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/v1.2/ \
		http://www.ameth.org/gimp/gtk/v1.2/

MAINTAINER=	vanilla@FreeBSD.ORG

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--includedir=${PREFIX}/include/glib12

MAN1=		glib12-config.1

post-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
