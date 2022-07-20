PORTNAME=	filebench
DISTVERSION=	1.5-alpha3-27
DISTVERSIONSUFFIX=	-g22620e6
CATEGORIES=	benchmarks

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	File system and storage benchmark

LICENSE=	CDDL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf libtool
USE_GITHUB=	yes
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}

GNU_CONFIGURE=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/*.so.0.0.0

.include <bsd.port.mk>
