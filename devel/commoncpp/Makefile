# New ports collection makefile for:	CommonC++
# Date created:				25 July 2000
# Whom:					David Sugar <dyfet@gnu.org>
#
# $FreeBSD$
#

PORTNAME=	CommonC++
PORTVERSION=	1.2.5.1
CATEGORIES=	devel
MASTER_SITES=	ftp://www.voxilla.org/pub/ape/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cplusplus

MAINTAINER=	dyfet@gnu.org

USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

pre-patch:
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|-release \$$\(LT_RELEASE\)||g'
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|l\$$ost_cv_thread_library|\$$ost_cv_thread_library|g ; \
		 s|=c_r|=pthread|g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/commoncpp
	${INSTALL_MAN} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/commoncpp
.endif

.include <bsd.port.mk>
