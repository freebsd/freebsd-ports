# New ports collection makefile for:	LeakTracer
# Date created:				04 Feb 2004
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	leaktracer
PORTVERSION=	2.4
CATEGORIES=	devel
MASTER_SITES=	http://www.andreasen.org/LeakTracer/ \
		http://freebsd.nsu.ru/distfiles/
DISTNAME=	LeakTracer

MAINTAINER=	danfe@regency.nsu.ru
COMMENT=	Trace and analyze memory leaks in C++ programs

INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
USE_PERL5_RUN=	yes
MAKE_ENV=	CXX="${CXX}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
PLIST_FILES=	bin/LeakCheck bin/leak-analyze lib/LeakTracer.so
PORTDOCS=	README README.html

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/LeakCheck ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/leak-analyze ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/LeakTracer.so ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
