# ex:ts=8
# New ports collection makefile for:	uds
# Date created:			Feb 27, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	uds
PORTVERSION=	0.9.4
CATEGORIES=	devel
MASTER_SITES=	http://frost.flewid.de/dist/

MAINTAINER=	ijliao@FreeBSD.org

USE_NEWGCC=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

pre-patch:
	@${PERL} -pi -e 's|\$$OPTFLAGS|\$$CFLAGS|g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

	@find ${WRKSRC} -name 'Makefile.in' | xargs ${PERL} -pi -e \
		's|install-data-hook|#install-data-hook|g ; \
		 s|-D_REENTRANT|-D_REENTRANT ${PTHREAD_CFLAGS}|g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g'

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/uds
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/uds
.endif

.include <bsd.port.mk>
