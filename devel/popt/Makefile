# New ports collection makefile for:	popt
# Date Created:				29 Dec 1999
# Whom:					Yuan-Chen Cheng <ycheng@sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	popt
PORTVERSION=	1.5
CATEGORIES=	devel
MASTER_SITES= ftp://ftp.rpm.org/pub/rpm/dist/rpm-3.0.x/

MAINTAINER=	ycheng@sinica.edu.tw

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

USE_LIBTOOL=	yes
INSTALL_SHLIBS=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN3=		popt.3

.include <bsd.port.mk>
