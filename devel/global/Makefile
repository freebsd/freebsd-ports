PORTNAME=	global
PORTVERSION=	6.6.12
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Source code tag system
WWW=		https://www.gnu.org/software/global/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe libtool ncurses perl5 shebangfix

CONFIGURE_ARGS=	--with-exuberant-ctags=${LOCALBASE}/bin/exctags \
		--with-python-interpreter=${LOCALBASE}/bin/python${PYTHON_DEFAULT} \
		--with-universal-ctags=${LOCALBASE}/bin/uctags
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_CSTD=	c99

INFO=		global

CPE_VENDOR=	gnu

SHEBANG_GLOB=	*.pl

.include <bsd.port.mk>
