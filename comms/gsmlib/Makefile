# ex:ts=8
# Ports collection makefile for:	gsmlib
# Date created:			Apr 24, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gsmlib
PORTVERSION=	1.9
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://www.pxh.de/fs/gsmlib/download/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	intl:${PORTSDIR}/devel/gettext

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	\
	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
	LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

MAN1=	gsmctl.1 gsmpb.1 gsmsendsms.1 gsmsmsstore.1
MAN7=	gsminfo.7
MAN8=	gsmsmsd.8

.include <bsd.port.mk>
