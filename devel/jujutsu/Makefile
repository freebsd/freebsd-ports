PORTNAME=	jujutsu
DISTVERSIONPREFIX=	v
DISTVERSION=	0.28.1
CATEGORIES=	devel

MAINTAINER=	se@FreeBSD.org
COMMENT=	Git-compatible VCS that is both simple and powerful
WWW=		https://jj-vcs.github.io/jj/latest/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libssh2.so:security/libssh2

USES=		cargo localbase ssl
USE_GITHUB=	yes
GH_ACCOUNT=	martinvonz
GH_PROJECT=	jj

PLIST_FILES=	bin/jj

do-install:
		${INSTALL_PROGRAM} ${WRKDIR}/target/release/jj \
			${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
