# New ports collection makefile for:	popt
# Date Created:				29 Dec 1999
# Whom:					Yuan-Chen Cheng <ycheng@sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	popt
PORTVERSION=	1.5.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.rpm.org/pub/rpm/dist/rpm-3.0.x/ \
		ftp://ftp.mirror.ac.uk/sites/ftp.rpm.org/pub/rpm/dist/rpm-3.0.x/

MAINTAINER=	ycheng@sinica.edu.tw

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

WRKSRC=		${WRKDIR}/${PORTNAME}-1.5

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN3=		popt.3

.include <bsd.port.mk>
