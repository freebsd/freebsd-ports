# New ports collection makefile for:	ccscript
# Date created:				26 July 2000
# Whom:					David Sugar <dyfet@gnu.org>
#
# $FreeBSD$
#

PORTNAME=	ccscript
PORTVERSION=	1.2.1
CATEGORIES=	lang
MASTER_SITES=	ftp://www.voxilla.org/pub/ccscript/

MAINTAINER=	dyfet@gnu.org

LIB_DEPENDS=	ccstd.0:${PORTSDIR}/devel/commoncpp

USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_AUTOCONF=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib -lpthread"

post-extract:
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|-release \$$\(LT_RELEASE\)||g'

.include <bsd.port.mk>
