# New ports collection makefile for:	popt
# Date Created:				29 Dec 1999
# Whom:					Yuan-Chen Cheng <ycheng@sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	popt
PORTVERSION=	1.7
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.rpm.org/pub/rpm/dist/%SUBDIR%/ \
		http://rpmfind.net/linux/rpm.org/rpm/dist/%SUBDIR%/ \
		ftp://ftp.mirror.ac.uk/sites/ftp.rpm.org/pub/rpm/dist/%SUBDIR%/ \
		http://gd.tuwien.ac.at/utils/rpm.org/dist/%SUBDIR%/ \
		ftp://sunsite.cnlab-switch.ch/mirror/rpm/dist/%SUBDIR%/ \
		ftp://ftp.sunfreeware.com/pub/freeware/SOURCES/
MASTER_SITE_SUBDIR=	rpm-4.1.x

MAINTAINER=	eik@FreeBSD.org
COMMENT=	A getopt(3) like library with a number of enhancements, from Redhat

BUILD_DEPENDS=	xgettext:${PORTSDIR}/devel/gettext

USE_LIBTOOL_VER=	15
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

MAN3=		popt.3

CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE} \
		--program-prefix=""

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
