# New ports collection makefile for:	gpsdrive
# Date Created:				16 April 2002
# Whom:					Marco Molteni <molter@gufi.org>
#
# $FreeBSD$
#

PORTNAME=	gpsdrive
PORTVERSION=	2.09
PORTREVISION=	3
CATEGORIES=	astro
MASTER_SITES=	http://www.gpsdrive.cc/           \
		http://gpsdrive.teachlinux.com/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A GPS navigation system

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

USE_GETOPT_LONG=yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk20
USE_INC_LIBTOOL_VER=	15
USE_REINPLACE=	yes

CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include \
		LDFLAGS=-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-garmin
INSTALLS_SHLIB=	yes

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

MAN1=		gpsdrive.1
MANLANG=	"" de es

post-patch:
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} 's|SUBDIRS = src po man|SUBDIRS = src man|' \
		${WRKSRC}/Makefile.in
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
