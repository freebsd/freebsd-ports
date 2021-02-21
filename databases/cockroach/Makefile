# $FreeBSD$

PORTNAME=	cockroach
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.7
CATEGORIES=	databases
MASTER_SITES=	https://binaries.cockroachdb.com/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	freebsd@jen20.com
COMMENT=	Cloud-native SQL database that survive disasters

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/src/github.com/cockroachdb/cockroach/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	"Only supported on amd64"

BUILD_DEPENDS=	autoconf:devel/autoconf \
		bash:shells/bash \
		cmake:devel/cmake

USES=		gmake go libedit

USE_RC_SUBR=	cockroach

NO_CCACHE=	yes

PLIST_FILES=	bin/cockroach

USERS=		cockroach
GROUPS=		cockroach

post-patch:
	@${REINPLACE_CMD} -e 's|LDFLAGS: -ledit|LDFLAGS: -L${LOCALBASE}/lib -ledit|g' \
			  -e 's|CPPFLAGS: -Ishim|CPPFLAGS: -I${LOCALBASE}/include -Ishim|g' \
		${WRKSRC}/src/github.com/cockroachdb/cockroach/vendor/github.com/knz/go-libedit/unix/editline_unix.go
	@${REINPLACE_CMD} -e 's|build -i -o|build -o|g' \
		${WRKSRC}/src/github.com/cockroachdb/cockroach/Makefile

do-build:
	@${SETENV} -i ${MAKE_ENV} ${GO_ENV} \
		${MAKE_CMD} -C ${WRKSRC} buildoss

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/cockroachdb/cockroach/cockroach ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
