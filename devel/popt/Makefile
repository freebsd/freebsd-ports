# New ports collection makefile for:	popt
# Date Created:				29 Dec 1999
# Whom:					Yuan-Chen Cheng <ycheng@sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	popt
PORTVERSION=	1.7
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.rpm.org/pub/rpm/dist/rpm-4.1.x/ \
		ftp://ftp.mirror.ac.uk/sites/ftp.rpm.org/pub/rpm/dist/rpm-4.1.x/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A getopt(3) like library with a number of enhancements, from Redhat

USE_GETTEXT=	yes
USE_LIBTOOL_VER=	13
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE} \
		--program-prefix=""
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN3=		popt.3

post-patch:
# avoid installing both charset.alias and locale.alias which conflict
# with libiconv
	@${REINPLACE_CMD} -E -e 's|(SUBDIRS[[:space:]]+=.*)intl|\1|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
