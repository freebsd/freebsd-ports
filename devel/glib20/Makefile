# New ports collection makefile for:   glib11-devel
# Version required:		1.1.13
# Date Created:			28 July 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.12 1999/01/05 00:56:06 vanilla Exp $
#

DISTNAME=	glib-1.1.13
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gimp.org/pub/gtk/v1.1/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/v1.1/ \
		http://www.ameth.org/gimp/gtk/v1.1/

MAINTAINER=	vanilla@FreeBSD.ORG

GNU_CONFIGURE=	yes

CONFIGURE_ENV=	INSTALL='$${INSTALL} -c'
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/glib11d
.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 300000
CONFIGURE_ARGS+=	--with-threads=none
.else
CONFIGURE_ARGS+=	--with-threads=uthread
.endif

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.post.mk>
