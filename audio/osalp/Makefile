# ex:ts=8
# Ports collection makefile for:	osalp
# Date created:			Jun 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	osalp
PORTVERSION=	0.7.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	lame:${PORTSDIR}/audio/lame \
		mpg123:${PORTSDIR}/audio/mpg123
LIB_DEPENDS=	vorbis.2:${PORTSDIR}/audio/libvorbis \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"
CONFIGURE_ARGS=	--enable-all

INSTALLS_SHLIB=	yes

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.mk>
