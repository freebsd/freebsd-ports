# New ports collection Makefile for:	zile
# Date created:		28 September 2000
# Whom:			jasone
#
# $FreeBSD$
#

PORTNAME=	zile
PORTVERSION=	2.3.4
CATEGORIES=	editors
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small emacs-like text editor

BUILD_DEPENDS=	help2man:${PORTSDIR}/misc/help2man

USE_LUA=	5.0+
LUA_COMPS=	lua:build
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-lgnuregex" \
		ac_cv_path_LUA="${LUA_CMD}"
CONFIGURE_ARGS=	--without-included-regex

MAN1=		zile.1
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

pre-build:
	@${RM} -f ${WRKSRC}/src/tbl_funcs.h
	@(cd ${BUILD_WRKSRC}/src; ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} tbl_funcs.h)

.include <bsd.port.mk>
