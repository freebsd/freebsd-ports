PORTNAME=	lhasa
DISTVERSION=	0.4.0
CATEGORIES=	archivers
MASTER_SITES=	https://github.com/fragglet/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	cs@innolan.dk
COMMENT=	Command line tool and library for parsing LHA archives
WWW=		https://fragglet.github.io/lhasa/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	bash>0:shells/bash

USES=		autoreconf cpe libtool
CPE_VENDOR=	lhasa_project
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-suffix=sa
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
