# New ports collection makefile for:	popt
# Date Created:				29 Dec 1999
# Whom:					Yuan-Chen Cheng <ycheng@sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	popt
PORTVERSION=	1.6.4
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.rpm.org/pub/rpm/dist/rpm-4.0.x/ \
		ftp://ftp.mirror.ac.uk/sites/ftp.rpm.org/pub/rpm/dist/rpm-4.0.x/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A getopt(3) like library with a number of enhancements, from Redhat

USE_GETTEXT=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN3=		popt.3

post-patch:
# avoid installing both charset.alias and locale.alias which conflict
# with libiconv
	@${REINPLACE_CMD} -E -e 's|(SUBDIRS[[:space:]]+=.*)intl|\1|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
