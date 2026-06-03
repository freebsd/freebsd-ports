PORTNAME=	DBD-cego
PORTVERSION=	1.5.4
CATEGORIES=	databases perl5
MASTER_SITES=	http://www.lemke-it.com/
PKGNAMEPREFIX=	p5-

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Cego DBI driver for Perl 5
WWW=		https://www.lemke-it.com/

LICENSE=	GPLv3

BUILD_DEPENDS=	p5-DBI>=1.631:databases/p5-DBI
RUN_DEPENDS=	p5-DBI>=1.631:databases/p5-DBI
LIB_DEPENDS=	liblfcbase.so:devel/lfcbase \
		liblfcxml.so:devel/lfcxml \
		libcego.so:databases/cego

USES=		compiler gmake perl5
USE_PERL5=	configure
CC:=		${CXX}
COMPILER_TYPE=	clang
CONFIGURE_ARGS+=	--prefix=${PREFIX}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/DBD/Cego/Cego.so

.include <bsd.port.mk>
