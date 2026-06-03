PORTNAME=	global
PORTVERSION=	6.6.14
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Source code tag system
WWW=		https://www.gnu.org/software/global/

LICENSE=	GPLv3+ LGPL20+ LGPL21+ BSD3CLAUSE BSD4CLAUSE
LICENSE_COMB=	multi

USES=		cpe libtool ncurses shebangfix

CONFIGURE_ARGS=	--with-exuberant-ctags=${LOCALBASE}/bin/exctags \
		--with-python-interpreter=${LOCALBASE}/bin/python${PYTHON_DEFAULT} \
		--with-universal-ctags=${LOCALBASE}/bin/uctags
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_CSTD=	c99

INFO=		global

CPE_VENDOR=	gnu

SHEBANG_GLOB=	*.pl

.include <bsd.port.mk>
