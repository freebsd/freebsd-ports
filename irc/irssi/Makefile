# New ports collection makefile for:	irssi
# Date created:			14 Apr 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	irssi
PORTVERSION=	0.7.91
CATEGORIES=	irc ipv6
MASTER_SITES=	http://xlife.dhs.org/irssi/files/

MAINTAINER=	jim@FreeBSD.org

LIB_DEPENDS=	glib12.3:${PORTSDIR}/devel/glib12 \
		intl.1:${PORTSDIR}/devel/gettext

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS=	--without-socks --with-textui --with-bot \
		--without-servertest

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014
CONFIGURE_ARGS+= --enable-ipv6
.else
CONFIGURE_ARGS+= --disable-ipv6
.endif

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib -lintl"

.include <bsd.port.post.mk>
