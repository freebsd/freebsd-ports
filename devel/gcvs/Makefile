# New ports collection makefile for:	gvcs
# Date Created:				28 Mar 2001
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	gcvs
PORTVERSION=	1.0
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	devel tk84
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cvsgui

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High-end interface client for CVS

BUILD_DEPENDS+=	wish8.4:${PORTSDIR}/x11-toolkits/tk84
RUN_DEPENDS+=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

USE_GETOPT_LONG=yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
BREAKS_IF_PEDANTIC=	yes
CONFIGURE_ARGS+=	--with-tclinclude=${LOCALBASE}/include/tcl8.4
CONFIGURE_ARGS+=	--with-tcllib=${LOCALBASE}/lib/tcl8.4
CONFIGURE_SCRIPT=	make_configure
MAN1=		cvs.1
MAN5=		cvs.5
MAN8=		cvsbug.8
INFO=		cvs cvsclient
WANT_AUTOMAKE_VER=	14
WANT_AUTOCONF_VER=	213

post-install:
	install-info ${PREFIX}/info/cvs.info ${PREFIX}/info/dir
	install-info ${PREFIX}/info/cvsclient.info ${PREFIX}/info/dir

.include <bsd.port.mk>
