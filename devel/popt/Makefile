# New ports collection makefile for:	popt
# Date Created:				29 Dec 1999
# Whom:					Yuan-Chen Cheng <ycheng@sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	popt
PORTVERSION=	1.7
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.rpm.org/pub/rpm/dist/%SUBDIR%/ \
		http://rpmfind.net/linux/rpm.org/rpm/dist/%SUBDIR%/ \
		ftp://ftp.mirrorservice.org/sites/ftp.rpm.org/pub/rpm/dist/%SUBDIR%/ \
		http://gd.tuwien.ac.at/utils/rpm.org/dist/%SUBDIR%/ \
		ftp://sunsite.cnlab-switch.ch/mirror/rpm/dist/%SUBDIR%/ \
		ftp://ftp.sunfreeware.com/pub/freeware/SOURCES/
MASTER_SITE_SUBDIR=	rpm-4.1.x

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A getopt(3) like library with a number of enhancements, from Redhat

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE} \
		--program-prefix=""
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes

MAN3=		popt.3

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
# gettext 0.13 or higher
USE_GETTEXT=	[^0-5]
PLIST_SUB+=	NLS=""
.endif

pre-configure:
# remove check for xgettext - popt do not use it anyway
	@${REINPLACE_CMD} -e \
		's:if test ! -f ../rpm.c:if test "1" != "1":' \
		${WRKSRC}/configure

.include <bsd.port.mk>
