PORTNAME=	ejdb
PORTVERSION=	2.72
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Embeddable JSON database engine library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libiowow.so:databases/iowow \
		libiwnet.so:net/iwnet

USES=		cmake compiler:c11
USE_GITHUB=	yes
GH_ACCOUNT=	Softmotions
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_LOCALBASE:PATH="${LOCALBASE}" \
		-DBUILD_EXAMPLES:BOOL=OFF

OPTIONS_DEFINE=	DOCS

post-patch:
	@${GREP} -Rl --null '#include <ejdb2/iowow/' ${WRKSRC}/src | \
		${XARGS} -0 ${REINPLACE_CMD} -e 's,ejdb2/iowow,iowow,'

.include <bsd.port.mk>
