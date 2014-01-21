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

OPTIONS_DEFINE=	DOCS

USES=		gmake perl5 shebangfix
SHEBANG_FILES=	leak-analyze
USE_LDCONFIG=	yes
USE_PERL5=	run
PLIST_FILES=	bin/LeakCheck bin/leak-analyze lib/LeakTracer.so
PORTDOCS=	README README.html

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/LeakCheck ${WRKSRC}/leak-analyze \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/LeakTracer.so ${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/README.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
