# New ports collection makefile for:	gvcs
# Date Created:				28 Mar 2001
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#    $MCom: ports/devel/gcvs/Makefile,v 1.1 2006/10/07 17:10:25 ahze Exp $

PORTNAME=	gcvs
PORTVERSION=	1.0
PORTREVISION=	11
PORTEPOCH=	1
CATEGORIES=	devel tk
MASTER_SITES=	SF/cvsgui/gCvs/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High-end interface client for CVS

BUILD_DEPENDS+=	wish8.4:${PORTSDIR}/x11-toolkits/tk84
RUN_DEPENDS+=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

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
USE_AUTOTOOLS=	automake:15:env autoconf:262:env

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800037
BROKEN=		does not compile
.endif

.include <bsd.port.post.mk>
