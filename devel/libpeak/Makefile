PORTNAME=	libpeak
PORTVERSION=	0.1.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/peak/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Parallel Events and Asynchronous tasKing Library

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=		amd64 i386 sparc64

USES=		gmake libtool perl5 shebangfix
USE_PERL5=	test
SHEBANG_FILES=	tests/test-suite.pl
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

do-test:
	( \
	    cd ${WRKSRC}/tests; \
	    alltests=`ls *.c | ${SED} -e 's|\.c||g'`; \
	    ${MAKE} $$alltests && ${SETENV} PERL5LIB=. ./test-suite.pl $$alltests \
	)

.include <bsd.port.mk>
