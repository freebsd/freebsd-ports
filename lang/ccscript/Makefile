# New ports collection makefile for:	ccscript
# Date created:				26 July 2000
# Whom:					David Sugar <dyfet@gnu.org>
#
# $FreeBSD$
#

PORTNAME=	ccscript
PORTVERSION=	1.4.1
CATEGORIES=	lang
MASTER_SITES=	ftp://www.voxilla.org/pub/freebsd/tarball/

MAINTAINER=	dyfet@gnu.org

LIB_DEPENDS=	ccstd-1.4.0:${PORTSDIR}/devel/commoncpp

USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_AUTOCONF=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib

#post-extract:
#	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
#		's|-release \$$\(LT_RELEASE\)||g'

post-install:
	(cd ${WRKSRC} ; make man)
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ccscript
	${INSTALL_MAN} ${WRKSRC}/doc/html/* ${PREFIX}/share/doc/ccscript
.endif

.include <bsd.port.mk>
