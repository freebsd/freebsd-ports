# Generated automatically from Makefile.in by configure.
# New ports collection makefile for:	vpb2
# Date created:				07 Sept 2000
# Whom:					David Sugar <dyfet@gnu.org>
#
# $FreeBSD$
#

PORTNAME=	vpb2
PORTVERSION=	2.0.3
CATEGORIES=	comms
MASTER_SITES=	ftp://www.voxilla.org/pub/vpb/

MAINTAINER=	dyfet@gnu.org

USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_AUTOCONF=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib

post-extract:
	@find ${WRKSRC} -name "Makefile.in" | \
		xargs ${REINPLACE_CMD} -e 's|-release \$$\(LT_RELEASE\)||g'

.include <bsd.port.mk>
