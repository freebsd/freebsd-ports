PORTNAME=	gtypist
DISTVERSION=	2.10.1
CATEGORIES=	games education
MASTER_SITES=	GNU

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Interactive typing tutor
WWW=		https://www.gnu.org/software/gtypist/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		iconv localbase ncurses shebangfix tar:xz

SHEBANG_FILES=	typefortune

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	EMACS=no

CPPFLAGS+=	-I${NCURSESINC}

INFO=		gtypist gtypist.cs gtypist.es

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
