# Created by: chuckr@FreeBSD.org

PORTNAME=	global
PORTVERSION=	6.6.6
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Source code tag system

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool ncurses perl5 shebangfix

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_CSTD=	c99

INFO=		global

SHEBANG_GLOB=	*.pl

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
