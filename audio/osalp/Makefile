# ex:ts=8
# Ports collection makefile for:	osalp
# Date created:			Jun 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	osalp
PORTVERSION=	0.7.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.ORG

BUILD_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123
LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"
CONFIGURE_ARGS=	--enable-blade --enable-mpg123 --enable-sox
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
