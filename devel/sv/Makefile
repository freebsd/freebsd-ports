PORTNAME=	sv
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2
CATEGORIES=	devel

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Semantic versioning in c99

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/UNLICENSE

USES=		autoreconf libtool pathfix
USE_GITHUB=	yes
GH_ACCOUNT=	uael
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

post-install:
	${RM} ${STAGEDIR}${PREFIX}/share/doc/libsv/UNLICENSE

.include <bsd.port.mk>
