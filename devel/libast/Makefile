# ports collection makefile for:	libast
# Date created:				7 September 2001
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	libast
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.eterm.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library of assorted spiffy things

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre \
		Imlib2.3:${PORTSDIR}/graphics/imlib2

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack
USE_LIBTOOL_VER=	15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_MMX) && (${ARCH} == "i386")
CONFIGURE_ARGS=	--enable-mmx
.endif

.include <bsd.port.post.mk>
