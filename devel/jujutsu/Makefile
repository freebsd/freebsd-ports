PORTNAME=	jujutsu
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.0
CATEGORIES=	devel

MAINTAINER=	se@FreeBSD.org
COMMENT=	Git-compatible VCS that is both simple and powerful
WWW=		https://github.com/martinvonz/jj/README.md

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	martinvonz
GH_PROJECT=	jj

__ARCH=		${ARCH:S/amd64/x86_64/}-unknown-${OPSYS:tl}

do-install:
		${INSTALL_PROGRAM} ${WRKDIR}/target/${__ARCH}/release/jj \
			${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
