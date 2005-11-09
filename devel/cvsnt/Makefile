# New ports collection makefile for:	cvsnt
# Date created:				21 Jan 2004
# Whom:					Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cvsnt
PORTVERSION=	2.5.02.2115
CATEGORIES=	devel
MASTER_SITES=	http://www.cvsnt.org/archive/

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	CVS clone

CONFLICTS=	cvs-1*

USE_INC_LIBTOOL_VER=	13
USE_RC_SUBR=	cvslockd.sh
CONFIGURE_ARGS=	--enable-fork\
		--disable-odbc --disable-postgres\
		--disable-mysql --disable-sqlite
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GETOPT_LONG=yes
USE_ICONV=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} ${PTHREAD_CFLAGS} -I${LOCALBASE}/include"\
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS} -L${LOCALBASE}/lib"\
		ac_cv_have_howl=no ac_cv_search_sw_discovery_run=no
LIB_DEPENDS=	expat.5:${PORTSDIR}/textproc/expat2

MAN1=		cvs.1
MAN5=		cvs.5
MLINKS=		cvs.1 cvsnt.1 cvs.5 cvsnt.5

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		requires wscanf, vswprintf
.endif

.include <bsd.port.post.mk>
