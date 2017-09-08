# $FreeBSD$

PORTNAME=	cockroach
PORTVERSION=	1.0.4
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
MASTER_SITES=	https://binaries.cockroachdb.com/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	james@jen20.com
COMMENT=	Cloud-native SQL database that survive disasters

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/src/github.com/cockroachdb/cockroach/LICENSE

BUILD_DEPENDS=	bash:shells/bash \
		cmake:devel/cmake \
		go:lang/go

USES=		gmake

USE_RC_SUBR=	cockroach

PLIST_FILES=	bin/cockroach

USERS=		cockroach
GROUPS=		cockroach

post-patch:
	@${REINPLACE_CMD} -e 's|-DCMAKE_CXX_FLAGS=-DNDEBUG)|-DCMAKE_CXX_FLAGS=-DNDEBUG) -DFAIL_ON_WARNINGS=OFF|g' \
	  	${WRKSRC}/src/github.com/cockroachdb/cockroach/build/common.mk

do-build:
	@${SETENV} -i PATH="${PATH}" \
		${MAKE_CMD} -C ${WRKSRC} buildoss

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/cockroachdb/cockroach/cockroach ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
