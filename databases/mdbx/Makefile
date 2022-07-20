PORTNAME=	mdbx
PORTVERSION=	0.11.2
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/
DISTNAME=	${GH_PROJECT}-amalgamated-${DISTVERSION}

MAINTAINER=	mahlon@martini.nu
COMMENT=	Lightning Memory-Mapped Database (Extended)

LICENSE=	OPENLDAP
LICENSE_NAME=	OpenLDAP Public License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		gmake
# No USE_GITHUB, we want the amalgamated build.
GH_ACCOUNT=	erthink
GH_PROJECT=	libmdbx
USE_LDCONFIG=	yes

MAKEFILE=	GNUmakefile
MAKE_ARGS=	mdbx tools

CFLAGS+=	-Wall -Werror -Wextra -Wpedantic -ffunction-sections \
		-fPIC -fvisibility=hidden -std=gnu11 -pthread -Wno-error=attributes

NO_WRKSUBDIR=	yes

PLIST_SUB=	VERSION=${PORTVERSION}

post-install:
	${RLN} libmdbx.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libmdbx.so
	${RLN} libmdbx.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libmdbx.so.0

.include <bsd.port.mk>
