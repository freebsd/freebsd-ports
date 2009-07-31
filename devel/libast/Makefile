# ports collection makefile for:	libast
# Date created:				7 September 2001
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	libast
PORTVERSION=	0.7
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	http://www.eterm.org/download/ \
		CRITICAL

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library of assorted spiffy things

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnomehack
USE_EFL=	imlib2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_MMX) && (${ARCH} == "i386")
CONFIGURE_ARGS=	--enable-mmx
.endif

.include <bsd.port.post.mk>
