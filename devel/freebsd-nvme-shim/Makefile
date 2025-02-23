PORTNAME=	freebsd-nvme-shim
DISTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	imp@FreeBSD.org
COMMENT=	FreeBSD implementations of Linux headers
WWW=		https://github.com/bsdimp/freebsd-nvme-shim

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USE_GITHUB=	yes
GH_ACCOUNT=	bsdimp
GH_TAGNAME=	freebsd-${DISTVERSION}

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/${PORTNAME})

post-install:
	${RM} ${STAGEDIR}${PREFIX}/include/${PORTNAME}/COPYRIGHT
	${RM} ${STAGEDIR}${PREFIX}/include/${PORTNAME}/NOTES

.include <bsd.port.mk>
