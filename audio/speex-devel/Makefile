# ex:ts=8
# Ports collection makefile for:	Speex
# Date created:			Jul 30, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	speex
PORTVERSION=	1.0.b1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Speex-${PORTVERSION:S/.b/beta/}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	ogg.4:${PORTSDIR}/audio/libogg \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_LIBTOOL=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
