# New ports collection makefile for:	le
# Date created:				16 October 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	le
PORTVERSION=	1.14.2
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.yar.ru/pub/source/le/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text editor with block and binary operations

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

MAN1=		le.1
PORTDOCS=	*
PORTDATA=	*
PLIST_FILES=	bin/le

MISC_DATA=	colors-black colors-blue colors-defbg colors-green \
		colors-white keymap-emacs mainmenu mainmenu-ru syntax
SRC_DATA=	le.hlp

do-install:
	cd ${WRKSRC}/src && ${INSTALL_PROGRAM} le ${PREFIX}/bin
	cd ${WRKSRC}/doc && ${INSTALL_MAN} le.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDATA)
	@${MKDIR} ${DATADIR}
.for file in ${MISC_DATA}
	cd ${WRKSRC}/misc && ${INSTALL_DATA} ${file} ${DATADIR}
.endfor
	@(cd ${WRKSRC}/misc && ${COPYTREE_SHARE} syntax.d ${DATADIR})
.for file in ${SRC_DATA}
	cd ${WRKSRC}/src && ${INSTALL_DATA} ${file} ${DATADIR}
.endfor
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in FEATURES HISTORY NEWS README TODO
	cd ${WRKSRC} && ${INSTALL_DATA} ${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
