# New ports collection makefile for:  madplay
# Date created:        26 November 2003
# Whom:                Sergey Akifyev <asa@gascom.ru>
#
# $FreeBSD$
#

PORTNAME=	madplay
PORTVERSION=	0.15.0b
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.mars.org/pub/mpeg/
MASTER_SITE_SUBDIR=	mad

MAINTAINER=	asa@gascom.ru
COMMENT=	Madplay MP3 player (part of MAD project)

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old \
		mad.2:${PORTSDIR}/audio/libmad \
		id3tag.2:${PORTSDIR}/audio/libid3tag

WANT_GNOME=	yes

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
ALL_TARGET=	all madtime

MAN1=		abxtest.1 madplay.1

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mesound}!=""
USE_GNOME+=	esound
PKGNAMESUFFIX=	-esound
.else
CONFIGURE_ARGS+=	--without-esd
.endif

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/madtime ${PREFIX}/bin

.include <bsd.port.post.mk>
