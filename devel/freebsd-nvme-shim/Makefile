PORTNAME=	freebsd-nvme-shim
PORTVERSION=	1.0.1
CATEGORIES=	devel

MAINTAINER=	imp@FreeBSD.org
COMMENT=	FreeBSD implementations of Linux headers
WWW=		https://github.com/bsdimp/freebsd-nvme-shim

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USE_GITHUB=	yes
GH_ACCOUNT=	bsdimp
GH_TAGNAME=	freebsd-1.0.1

NO_BUILD=	yes

do-install:
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/${PORTNAME})

.include <bsd.port.mk>
