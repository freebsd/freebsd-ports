# New ports collection makefile for:	bayonne
# Date created:				10 September 2000
# Whom:					David Sugar <dyfet@gnu.org>
#
# $FreeBSD$
#

PORTNAME=	bayonne
PORTVERSION=	0.5.3
CATEGORIES=	comms
MASTER_SITES=	ftp://www.voxilla.org/pub/bayonne/

MAINTAINER=	dyfet@gnu.org

LIB_DEPENDS=	ccstd-1.4.0:${PORTSDIR}/devel/commoncpp \
		ccscript-1.4.0:${PORTSDIR}/lang/ccscript \
		ccaudio.0:${PORTSDIR}/audio/ccaudio \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_AUTOCONF=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib
PLIST_SUB=	BAYONNE_VERSION=%{PORT_VERSION}

post-extract:
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|-release \$$\(LT_RELEASE\)||g'

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
