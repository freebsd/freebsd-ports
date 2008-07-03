# New ports collection makefile for:	le
# Date created:				16 October 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	le
PORTVERSION=	1.13.7
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
PORTDATA=	colors-black colors-blue colors-defbg colors-green \
		colors-white keymap-emacs le.hlp mainmenu mainmenu-ru syntax
PLIST_FILES+=	bin/le

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 502010
GNU_REGEX_H=	gnu/regex.h
.else
GNU_REGEX_H=	gnuregex.h
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|@LIBOBJS@||g ; \
		 s|@ALLOCA@||g' ${WRKSRC}/lib/Makefile.in
	@${REINPLACE_CMD} -e 's|<regex.h>|<${GNU_REGEX_H}>|g' \
		${WRKSRC}/src/highli.h

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
