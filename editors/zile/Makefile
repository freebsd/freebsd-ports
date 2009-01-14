# New ports collection Makefile for:	zile
# Date created:		28 September 2000
# Whom:			jasone
#
# $FreeBSD$
#

PORTNAME=	zile
PORTVERSION=	2.3.0
CATEGORIES=	editors
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small emacs-like text editor

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-lgnuregex"
CONFIGURE_ARGS=	--without-included-regex

MAN1=		zile.1
INFO=		zile
PLIST_FILES=	bin/zile %%DATADIR%%/FAQ %%DATADIR%%/dotzile.sample
PLIST_DIRS=	%%DATADIR%%

post-patch:
	@${REINPLACE_CMD} -e \
		's|<regex\.h>|<gnu/regex.h>|g ; \
		 s|-pedantic||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|"regex\.h"|<gnu/regex.h>|g' ${WRKSRC}/src/search.c
	@${REINPLACE_CMD} -e \
		's|: install-exec-local|:|g' ${WRKSRC}/lib/Makefile.in

.include <bsd.port.mk>
