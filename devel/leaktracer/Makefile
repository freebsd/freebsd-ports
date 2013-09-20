# Created by: Alexey Dokuchaev <danfe@regency.nsu.ru>
# $FreeBSD$

PORTNAME=	leaktracer
PORTVERSION=	2.4
CATEGORIES=	devel
MASTER_SITES=	http://www.andreasen.org/LeakTracer/ \
		http://freebsd.nsu.ru/distfiles/
DISTNAME=	LeakTracer

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Trace and analyze memory leaks in C++ programs

USES=		perl5
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_PERL5=	run
PLIST_FILES=	bin/LeakCheck bin/leak-analyze lib/LeakTracer.so
PORTDOCS=	README README.html

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/LeakCheck ${WRKSRC}/leak-analyze \
		${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/LeakTracer.so ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/README.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
