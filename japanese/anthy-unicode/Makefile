PORTNAME=	anthy-unicode
DISTVERSION=	1.0.0.20260127
CATEGORIES=	japanese
MASTER_SITES=	https://github.com/fujiwarat/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Library for Japanese text input
WWW=		https://github.com/fujiwarat/anthy-unicode/

LICENSE=	GPLv2 LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/alt-cannadic/COPYING
LICENSE_FILE_LGPL21+ =	${WRKSRC}/COPYING

USES=		autoreconf libtool pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

ELISPDIR=	share/emacs/site-lisp/${PORTNAME}
PLIST_SUB=	ELISPDIR=${ELISPDIR}

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/src-util/*.el ${STAGEDIR}${PREFIX}/${ELISPDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ELISP ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
