# New ports collection makefile for:	CommonC++
# Date created:				25 July 2000
# Whom:					David Sugar <dyfet@gnu.org>
#
# $FreeBSD$
#

PORTNAME=	CommonC++
PORTVERSION=	1.2.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cplusplus

MAINTAINER=	dyfet@gnu.org

USE_GMAKE=	yes
USE_CONFIGURE=	yes
USE_LIBTOOL=	yes
#USE_AUTOCONF=	yes
INSTALLS_SHLIB=	yes
#AUTOCONF=	autoconf && ${PERL} -pi -e 's|-lpthread|-pthread|g ; \
#		s|l\$$ost_cv_thread_library|\$$ost_cv_thread_library|g' \
#			${WRKSRC}/configure
#
# I had immense problems with autoconf generated on xBSD 4.0 where the
# generated configure would mangle library names.

post-extract:
	cd ${WRKSRC} ; ./configure
#	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
#		's|-release \$$\(LT_RELEASE\)||g'

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/commoncpp
	${INSTALL_MAN} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/commoncpp
.endif

.include <bsd.port.mk>
