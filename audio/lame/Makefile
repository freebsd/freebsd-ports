# ports collection makefile for:   lame
# Date created:        11 January 1998
# Whom:                yoshiaki Uchikawa
#
# $FreeBSD$
#

PORTNAME=	lame
PORTVERSION=	3.91
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://lame.sourceforge.net/pub/
MASTER_SITE_SUBDIR=	lame

MAINTAINER=	yoshiaki@kt.rim.or.jp

.if ${MACHINE_ARCH} == "i386"
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
.endif

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_GNOMENG=	yes
WANT_GNOME=	yes
CONFIGURE_ARGS=	--enable-nasm --enable-mp3rtp

.include <bsd.port.pre.mk>

.if (${HAVE_GNOME:Mgtk12}!="" || defined(WITH_GTK)) && !defined(WITHOUT_GTK)
USE_GNOME+=	gtk12
PLIST_SUB+=	WITH_GTK=''
PKGNAMESUFFIX=	-gtk
.else
PLIST_SUB+=	WITH_GTK='@comment '
.endif

MAN1=		lame.1

post-build:
.if ${HAVE_GNOME:Mgtk12}!="" && !defined(WITHOUT_GTK)
	cd ${WRKSRC}/frontend && make mp3x
.endif

post-install:
.if ${HAVE_GNOME:Mgtk12}!="" && !defined(WITHOUT_GTK)
	${INSTALL_PROGRAM} ${WRKSRC}/frontend/mp3x ${PREFIX}/bin/
.endif

.include <bsd.port.post.mk>
