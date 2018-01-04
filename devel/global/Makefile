# Created by: chuckr@FreeBSD.org
# $FreeBSD$

PORTNAME=	global
PORTVERSION=	6.6.1
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Source code tag system

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USES=		libtool ncurses perl5 shebangfix

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
