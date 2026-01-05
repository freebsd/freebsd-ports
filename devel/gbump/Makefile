PORTNAME=	gbump
PORTVERSION=	1.3.0
CATEGORIES=	devel
MASTER_SITES=	CRATESIO
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${CARGO_CRATE_EXT}

MAINTAINER=	ports@freebsd.org
COMMENT=	Git tag semantic version bumper
WWW=		https://github.com/nbari/gbump

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libssh2.so:security/libssh2

USES=		cargo localbase ssl

PLIST_FILES=	bin/gbump

.include <bsd.port.mk>
