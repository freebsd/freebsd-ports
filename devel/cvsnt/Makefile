# New ports collection makefile for:	cvsnt
# Date created:				21 Jan 2004
# Whom:					Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cvsnt
PORTVERSION=	2.5.01.1927
CATEGORIES=	devel
MASTER_SITES=	http://www.cvsnt.org/archive/

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	CVS clone

CONFLICTS=	cvs-1*

USE_LIBLTDL=	yes
USE_INC_LIBTOOL_VER=	13
USE_RC_SUBR=	cvslockd.sh
CONFIGURE_ARGS=	--enable-fork
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GETOPT_LONG=yes
USE_ICONV=	yes
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
LIB_DEPENDS=	expat.5:${PORTSDIR}/textproc/expat2

MAN1=		cvs.1
MAN5=		cvs.5
MLINKS=		cvs.1 cvsnt.1 cvs.5 cvsnt.5

.if exists(/usr/include/gssapi.h)
PLIST_SUB=	GSERVER=""
.else
PLIST_SUB=	GSERVER="@comment "
CONFIGURE_ARGS+=--disable-gserver
.endif

.include <bsd.port.mk>
