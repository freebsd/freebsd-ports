# New ports collection makefile for:	cvsnt
# Date created:				21 Jan 2004
# Whom:					Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cvsnt
PORTVERSION=	2.5.04.3236
CATEGORIES=	devel
MASTER_SITES=	http://www.cvsnt.org/archive/

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	CVS clone

CONFLICTS=	cvs-1*

GNU_CONFIGURE=	yes
USE_RC_SUBR=	cvslockd.sh
CONFIGURE_ARGS=	--enable-fork --enable-rcs \
		--disable-odbc --disable-postgres\
		--disable-mysql --disable-sqlite\
		--without-howl
USE_ICONV=	yes
USE_GNOME=	libxml2
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} ${PTHREAD_CFLAGS} -I${LOCALBASE}/include"\
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS} -L${LOCALBASE}/lib"
LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2\
		pcre.0:${PORTSDIR}/devel/pcre
PLIST_SUB=	PORTVERSION="${PORTVERSION}"

MAN1=		cvs.1 cvslockd.1
MAN5=		cvs.5 PServer.5 Plugins.5
MLINKS=		cvs.1 cvsnt.1 cvs.5 cvsnt.5

post-configure:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" \
		${WRKSRC}/rcs/common.cpp

.include <bsd.port.mk>
