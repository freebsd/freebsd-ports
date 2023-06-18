PORTNAME=	trompeloeil
DISTVERSIONPREFIX=	v
DISTVERSION=	44
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Header only C++14 mocking framework
WWW=		https://github.com/rollbear/trompeloeil

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

TEST_DEPENDS=	${LOCALBASE}/include/catch2/catch.hpp:devel/catch \
		criterion>0:devel/criterion

USES=		cmake:testing # unclear how to run tests, see https://github.com/rollbear/trompeloeil/issues/287

USE_GITHUB=	yes
GH_ACCOUNT=	rollbear

NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

post-install:
	@cd ${STAGEDIR}${DOCSDIR} && \
		${RM} LICENSE_1_0.txt && \
		${MV} docs/* . && \
		${RMDIR} docs

.include <bsd.port.mk>
