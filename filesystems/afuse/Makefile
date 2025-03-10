PORTNAME=	afuse
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
CATEGORIES=	filesystems
MASTER_SITES=	https://BSDforge.com/projects/source/sysutils/afuse/
PKGNAMEPREFIX=	fusefs-

PATCH_SITES=	https://github.com/pcarrier/afuse/commit/
PATCHFILES=	30057222cc58ffe1f8c0889fce8da314d5364691.patch:-p1

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	File system automounting implemented in user-space using FUSE
WWW=		https://github.com/pcarrier/afuse

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf cpe fuse pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	pcarrier

GNU_CONFIGURE=	yes

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

DOCS_SUB_FILES=	pkg-message

post-install:
	${INSTALL_MAN} ${FILESDIR}/afuse.1 ${STAGEDIR}${PREFIX}/share/man/man1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
