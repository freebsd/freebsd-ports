# New ports collection makefile for:	gcompris
# Date created:				21 July 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gcompris
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple Gnome-based education game for children starting at 3

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2
RUN_DEPENDS=	ogg123:${PORTSDIR}/audio/vorbis-tools

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs gnomecanvas
USE_LIBTOOL=	yes
USE_PERL5_BUILD=yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

CONFLICTS=	gcompris2*

post-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
