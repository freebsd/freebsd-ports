PORTNAME=	patch
PORTVERSION=	2.8
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	GNU patch utility
WWW=		https://savannah.gnu.org/projects/patch/

LICENSE=	GPLv3+

TEST_DEPENDS=	bash:shells/bash

USES=		charsetfix cpe tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g
CPE_VENDOR=	gnu

TEST_TARGET=	check

PLIST_FILES=	bin/gpatch share/man/man1/gpatch.1.gz
PORTDOCS=	AUTHORS NEWS README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == i386
CONFIGURE_ARGS+=	--disable-year2038
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^LOG_COMPILER =/,+1s|$$(SHELL)|bash|' \
		${WRKSRC}/tests/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
