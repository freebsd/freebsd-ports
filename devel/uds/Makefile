# ex:ts=8
# New ports collection makefile for:	uds
# Date created:			Feb 27, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	uds
PORTVERSION=	1.0.6
CATEGORIES=	devel
MASTER_SITES=	http://frost.flewid.de/dist/

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
USE_GCC=	3.1
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

	@${FIND} ${WRKSRC} -name 'Makefile.in' | ${XARGS} ${REINPLACE_CMD} -e \
		's|install-data-hook|#install-data-hook|g ; \
		 s|-D_REENTRANT|-D_REENTRANT ${PTHREAD_CFLAGS}|g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g'

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
