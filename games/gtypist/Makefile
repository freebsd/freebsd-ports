PORTNAME=	gtypist
PORTVERSION=	2.10
PORTREVISION=	1
CATEGORIES=	games education
MASTER_SITES=	GNU

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Interactive typing tutor
WWW=		https://www.gnu.org/software/gtypist/

LICENSE=	GPLv3

USES=		iconv localbase ncurses shebangfix tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	EMACS=no
CPPFLAGS+=	-I${NCURSESINC}

INFO=		gtypist gtypist.cs gtypist.es

SHEBANG_FILES=	typefortune

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
