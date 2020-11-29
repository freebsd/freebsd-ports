# Created by: Mahlon E. Smith <mahlon@martini.nu>
# $FreeBSD$

PORTNAME=	mdbx
PORTVERSION=	0.9.2
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

PLIST_SUB=	VERSION=${PORTVERSION}
MAKEFILE=	GNUmakefile
NO_WRKSUBDIR=	yes
USE_LDCONFIG=	yes

CFLAGS+=	-Wall -Werror -Wextra -Wpedantic -ffunction-sections \
		-fPIC -fvisibility=hidden -std=gnu11 -pthread -Wno-error=attributes
MAKE_ARGS=	mdbx tools

# No USE_GITHUB, we want the amalgamated build.
GH_ACCOUNT=	erthink
GH_PROJECT=	libmdbx

post-install:
	${LN} -sf libmdbx.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libmdbx.so
	${LN} -sf libmdbx.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libmdbx.so.0

.include <bsd.port.mk>
