# New ports collection makefile for:	XDTP (XML Document Transfer Program)
# Date created:				11 October 2005
# Whom:					Masanori OZAWA (ozawa@ongs.co.jp)
#
# $FreeBSD$
#

PORTNAME=	xdtp
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES+=	http://www.ongs.co.jp/projects/xdtp/
DISTNAME=	xdtp-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ozawa@ongs.co.jp
COMMENT=	XDTP (XML Document Transfer Program)

LIB_DEPENDS=	glibmm-2.4:${PORTSDIR}/devel/glibmm

USE_LDCONFIG=	yes
USE_GNOME=	libxml2 libxslt pkgconfig
GNU_CONFIGURE=	yes

OPTIONS=	GDK	"Build with Gdk-Pixbuf" on \
		DEBUG	"Build with debug option" off \
		INCLUDE	"Install with XDTP include files" on

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

.if defined(WITH_GDK)
USE_GNOME+=	gtk20
.else
CONFIGURE_ENV+=	WITHOUT_GDK="yes"
MAKE_ARGS+=	-DWITHOUT_GDK
.endif

.if defined(WITH_DEBUG)
MAKE_ARGS+=	-DDEBUG
.endif

.if defined(WITH_INCLUDE)
PLIST_SUB+=	XDTP_INC=""
.else
MAKE_ARGS+=	-DWITHOUT_INCLUDE
PLIST_SUB+=	XDTP_INC="@comment "
.endif

.include <bsd.port.post.mk>
