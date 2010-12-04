# New ports collection makefile for:	popt
# Date Created:				29 Dec 1999
# Whom:					Yuan-Chen Cheng <ycheng@sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	popt
PORTVERSION=	1.16
CATEGORIES=	devel
MASTER_SITES=	http://rpm5.org/files/popt/

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	A getopt(3) like library with a number of enhancements, from Redhat

CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE} \
		--program-prefix=""
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehack
USE_ICONV=	yes
USE_LDCONFIG=	yes

MAN3=		popt.3

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
USE_GETTEXT=	yes
.endif

.include <bsd.port.mk>
