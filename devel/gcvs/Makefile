# New ports collection makefile for:	gvcs
# Date Created:				28 Mar 2001
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	gcvs
PORTVERSION=	1.0a7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cvsgui

MAINTAINER=	dinoex@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt
BUILD_DEPENDS+=	wish8.3:${PORTSDIR}/x11-toolkits/tk83
RUN_DEPENDS+=	wish8.3:${PORTSDIR}/x11-toolkits/tk83

USE_X_PREFIX=	yes
USE_GTK=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
BREAKS_IF_PEDANTIC=	yes
CONFIGURE_ARGS+=	--with-tclinclude=${LOCALBASE}/include/tcl8.3
CONFIGURE_ARGS+=	--with-tcllib=${LOCALBASE}/lib/tcl8.3
LIBS+=		-lgnugetopt
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib/ ${LIBS}"
MAN1=		cvs.1
MAN5=		cvs.5
MAN8=		cvsbug.8

.include <bsd.port.mk>
