# Created by: Masanori OZAWA (ozawa@ongs.co.jp)
# $FreeBSD$

PORTNAME=	xdtp
PORTVERSION=	1.3.1
PORTREVISION=	4
CATEGORIES=	japanese
MASTER_SITES+=	http://www.ongs.co.jp/projects/xdtp/
DISTNAME=	xdtp-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ozawa@ongs.co.jp
COMMENT=	XDTP (XML Document Transfer Program)

LIB_DEPENDS=	glibmm-2.4:${PORTSDIR}/devel/glibmm

USE_LDCONFIG=	yes
USE_GNOME=	libxml2 libxslt
USES=	pkgconfig
GNU_CONFIGURE=	yes
MAKE_JOB_UNSAFE=	yes

OPTIONS_DEFINE=	GDK DEBUG INCLUDE
GDK_DESC=	Build with Gdk-Pixbuf
INCLUDE_DESC=	Install with XDTP include files

OPTIONS_DEFAULT=	GDK INCLUDE

.include <bsd.port.options.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

.if ${PORT_OPTIONS:MGDK}
USE_GNOME+=	gtk20
.else
CONFIGURE_ENV+=	WITHOUT_GDK="yes"
MAKE_ARGS+=	-DWITHOUT_GDK
.endif

.if ${PORT_OPTIONS:MDEBUG}
MAKE_ARGS+=	-DDEBUG
.endif

.if ${PORT_OPTIONS:MINCLUDE}
PLIST_SUB+=	XDTP_INC=""
.else
MAKE_ARGS+=	-DWITHOUT_INCLUDE
PLIST_SUB+=	XDTP_INC="@comment "
.endif

.include <bsd.port.mk>
