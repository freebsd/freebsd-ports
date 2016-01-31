# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	le
PORTVERSION=	1.14.9
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.yar.ru/pub/source/le/%SUBDIR%/ \
		http://mirrors.rit.edu/zi/
MASTER_SITE_SUBDIR=	. old

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Text editor with block and binary operations

LICENSE=	GPLv3

USES=		ncurses tar:bzip2
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include

MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	*
PORTDATA=	*
PLIST_FILES=	bin/le \
		man/man1/le.1.gz

MISC_DATA=	colors-black colors-blue colors-defbg colors-green \
		colors-white keymap-emacs mainmenu mainmenu-ru syntax
SRC_DATA=	le.hlp

do-install:
	cd ${WRKSRC}/src && ${INSTALL_PROGRAM} le ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/doc && ${INSTALL_MAN} le.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for file in ${STAGEDIR}${MISC_DATA}
	cd ${WRKSRC}/misc && ${INSTALL_DATA} ${file} ${STAGEDIR}${DATADIR}
.endfor
	@(cd ${WRKSRC}/misc && ${COPYTREE_SHARE} syntax.d ${STAGEDIR}${DATADIR})
.for file in ${SRC_DATA}
	cd ${WRKSRC}/src && ${INSTALL_DATA} ${file} ${STAGEDIR}${DATADIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in FEATURES HISTORY NEWS README TODO
	cd ${WRKSRC} && ${INSTALL_DATA} ${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
