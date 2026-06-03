PORTNAME=	lhasa
DISTVERSION=	0.5.0
CATEGORIES=	archivers
MASTER_SITES=	https://github.com/fragglet/${PORTNAME}/releases/download/v${DISTVERSION}/ \
		https://soulsphere.org/projects/${PORTNAME}/

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Free Software LHA implementation
WWW=		https://fragglet.github.io/lhasa/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING.md

TEST_DEPENDS=	bash>0:shells/bash

USES=		autoreconf cpe libtool
CPE_VENDOR=	lhasa_project
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-suffix=sa
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PLIST_SUB=	LIBVERSION=0.1.0 VERSION=${DISTVERSION}
PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
