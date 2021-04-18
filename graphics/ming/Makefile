# Created by: Akinori MUSHA aka knu <knu@idaemons.org>

PORTNAME=	ming
DISTVERSIONPREFIX=	ming-
DISTVERSION=	0_4_8
CATEGORIES=	graphics

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Flash 4/5 movie output library with many languages support

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSE_GPL2
LICENSE_FILE_LGPL21=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libgif.so:graphics/giflib \
		libpng.so:graphics/png

USES=		autoreconf bison gmake libtool localbase pathfix shebangfix

CFLAGS+=	-fcommon # https://github.com/libming/libming/issues/55
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/ming
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	*

USE_GITHUB=	yes
GH_ACCOUNT=	libming
GH_PROJECT=	libming

CONFLICTS_INSTALL=	ja-ming

PORTSCOUT=	limit:^ming-

SHEBANG_FILES=	util/cws2fws

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/ming/ ${STAGEDIR}${PREFIX}/include/ming/blocks/ ${STAGEDIR}${PREFIX}/include/ming/util/
	cd ${WRKSRC}/util/ && ${INSTALL_SCRIPT} cws2fws ming-config ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/ && ${INSTALL_DATA} *.h src/*.h ${STAGEDIR}${PREFIX}/include/ming/
	cd ${WRKSRC}/src/blocks/ && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/ming/blocks/
	cd ${WRKSRC}/util/ && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/ming/util/

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/ ${STAGEDIR}${DOCSDIR}/util/
	cd ${WRKSRC}/ && ${INSTALL_DATA} HISTORY NEWS README TODO ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/util/ && ${INSTALL_DATA} README TIPS TODO swftoperl.html ${STAGEDIR}${DOCSDIR}/util/

.include <bsd.port.mk>
