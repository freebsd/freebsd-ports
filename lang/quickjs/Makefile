PORTNAME=	quickjs
DISTVERSION=	2025.09.13-20251018
CATEGORIES=	lang devel
#MASTER_SITES=	https://bellard.org/${PORTNAME}/
#DISTNAME=	${PORTNAME}-${DISTVERSION:S/./-/g}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Embeddable Javascript interpreter in C
WWW=		https://bellard.org/quickjs/

LICENSE=	MIT

USES=		compiler:c11 cpe gmake tar:xz
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	bellard
GH_TAGNAME=	eb2c890

CPE_VENDOR=	${PORTNAME}_project

CONFLICTS=	quickjs

TEST_TARGET=	test

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
post-patch:
	@${REINPLACE_CMD} -e 's/%%GCC_DEFAULT%%/${GCC_DEFAULT}/' \
		${WRKSRC}/Makefile
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libquickjs.so

.include <bsd.port.post.mk>
