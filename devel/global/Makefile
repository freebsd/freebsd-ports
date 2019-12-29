# Created by: chuckr@FreeBSD.org
# $FreeBSD$

PORTNAME=	global
PORTVERSION=	6.6.4
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Source code tag system

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	DOCS

USES=		libtool ncurses perl5 shebangfix

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_CSTD=	c99

INFO=		global
PORTDOCS=	AUTHORS ChangeLog FAQ INSTALL LICENSE NEWS README THANKS

SHEBANG_GLOB=	*.pl

post-patch:
	@${REINPLACE_CMD} -e '/^gtags_DATA = / s|AUTHOR.*THANKS||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '1d' ${WRKSRC}/plugin-factory/pygments_parser.py.in

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
