PORTNAME=	gdbm
PORTVERSION=	1.26
CATEGORIES=	databases
MASTER_SITES=	GNU

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	GNU database manager
WWW=		https://www.gnu.org.ua/software/gdbm/

LICENSE=	GPLv3+

USES=		gmake libtool:keepla readline
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes

INFO=		gdbm

OPTIONS_DEFINE=	COMPAT NLS
OPTIONS_SUB=	yes

COMPAT_DESC=	Enable dbm/ndbm compatibility
COMPAT_CONFIGURE_ENABLE=	libgdbm-compat

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

.include <bsd.port.mk>
