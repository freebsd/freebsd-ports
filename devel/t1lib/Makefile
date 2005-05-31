# ex:ts=8
# New ports collection makefile for:	libt1
# Date created:			13, May, 1999
# Whom:				Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	t1lib
PORTVERSION=	5.0.1
PORTEPOCH=	1
CATEGORIES=	devel
### 5.0.2 seems to cause problems with xpdf
### 5.0.1 has been vanished from most of ibilio/sunsite mirror sites
#MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITES=	http://sunsite.rediris.es/sites2/ibiblio.org/linux/%SUBDIR%/
MASTER_SITE_SUBDIR=	libs/graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Type 1 Rasterizer Library for UNIX/X11

USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_INC_LIBTOOL_VER=15
ALL_TARGET=	without_doc
INSTALLS_SHLIB=	yes

.if !defined(WITHOUT_X11)
USE_XLIB=	yes
CONFIGURE_ARGS+=	--with-x
PLIST_SUB+=	X11=""
.else
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=	X11="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|^LIBTOOL[ ]*=.*|LIBTOOL=${LIBTOOL}|' \
		${WRKSRC}/xglyph/Makefile.in ${WRKSRC}/lib/type1/Makefile.in \
		${WRKSRC}/lib/t1lib/Makefile.in ${WRKSRC}/lib/Makefile.in \
		${WRKSRC}/type1afm/Makefile.in ${WRKSRC}/examples/Makefile.in


post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/t1lib_doc.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
