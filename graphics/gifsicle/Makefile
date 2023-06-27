PORTNAME=	gifsicle
PORTVERSION=	1.94
CATEGORIES=	graphics
MASTER_SITES=	https://www.lcdf.org/gifsicle/

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Manipulates GIF images and animations
WWW=		https://www.lcdf.org/gifsicle/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_mips=		fails to build: undefined reference to '__sync_add_and_fetch_4'
BROKEN_mips64=		fails to build: undefined reference to '__sync_add_and_fetch_4'

FLAVORS=		x11 nox11
FLAVOR?=		${FLAVORS:[1]}
nox11_PKGNAMESUFFIX=	-nox11

USES=		cpe

CPE_VENDOR=	gifsicle_project

GNU_CONFIGURE=	yes

PORTDOCS=	NEWS.md README.md
PLIST_FILES=	bin/gifdiff bin/gifsicle \
		man/man1/gifdiff.1.gz man/man1/gifsicle.1.gz

.if ${FLAVOR} == x11
USES+=			xorg
USE_XORG=		ice sm x11
CONFIGURE_ARGS=		--enable-gifview \
			--with-x
PLIST_FILES+=		bin/gifview \
			man/man1/gifview.1.gz
CONFLICTS_INSTALL=	gifsicle-nox11
.else
CONFLICTS_INSTALL=	gifsicle
.endif

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
