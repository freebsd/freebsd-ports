# New ports collection makefile for:	le
# Date created:				16 October 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	le
PORTVERSION=	1.13.8
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.yar.ru/pub/source/le/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text editor with block and binary operations

USE_BZIP2=	yes
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-lgnuregex"

MAN1=		le.1
PORTDOCS=	FEATURES HISTORY NEWS README TODO
PORTDATA=	${MISC_DATA} ${SRC_DATA}
PLIST_FILES=	bin/le

MISC_DATA=	colors-black colors-blue colors-defbg colors-green \
		colors-white keymap-emacs mainmenu mainmenu-ru syntax
SRC_DATA=	le.hlp

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 502010
GNU_REGEX_H=	gnu/regex.h
.else
GNU_REGEX_H=	gnuregex.h
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|@LIBOBJS@||g ; \
		 s|@ALLOCA@||g' ${WRKSRC}/lib/Makefile.in
.for file in configure src/search.cc src/highli.h
	@${REINPLACE_CMD} -e 's|<regex.h>|<${GNU_REGEX_H}>|g' ${WRKSRC}/${file}
.endfor

do-install:
	cd ${WRKSRC}/src && ${INSTALL_PROGRAM} le ${PREFIX}/bin
	cd ${WRKSRC}/doc && ${INSTALL_MAN} le.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDATA)
	@${MKDIR} ${DATADIR}
.for file in ${MISC_DATA}
	cd ${WRKSRC}/misc && ${INSTALL_DATA} ${file} ${DATADIR}
.endfor
.for file in ${SRC_DATA}
	cd ${WRKSRC}/src && ${INSTALL_DATA} ${file} ${DATADIR}
.endfor
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	cd ${WRKSRC} && ${INSTALL_DATA} ${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
