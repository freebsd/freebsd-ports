PORTNAME=	hxavi
DISTVERSION=	1.2.1
CATEGORIES=	editors
MASTER_SITES=	https://hxavi.net/files/
DISTNAME=	${PORTNAME}-${DISTVERSION}.20260309

MAINTAINER=	satoumc@hxavi.net
COMMENT=	Lightweight binary (hex) editor for vi and Vim users
WWW=		https://hxavi.net/en/en-home/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/doc/copyright

USES=		ncurses
PLIST_SUB=	LIBNAMEVAR=${LIBNAMEVAR}
LIBNAMEVAR=	lib/${PORTNAME}/${PORTNAME}-${DISTVERSION}/lib

OPTIONS_DEFINE=		DOCS MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hxavi ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/${LIBNAMEVAR}
	@cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/${LIBNAMEVAR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

post-install-MANPAGES-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/hxavi_en_ascii.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/hxavi.1
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/man/ja_JP.UTF-8/man1
	${INSTALL_MAN} ${WRKSRC}/man/hxavi_ja_utf8.1 \
		${STAGEDIR}${PREFIX}/share/man/ja_JP.UTF-8/man1/hxavi.1

.include <bsd.port.mk>
