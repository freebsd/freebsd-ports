# ex:ts=8
# New ports collection makefile for:	regexx
# Date created:			Mar 2, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	regexx
PORTVERSION=	0.98.1
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A complete regular expressions C++ solution

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
MAKE_ENV+=      INCLUDES="-I${WRKSRC}/pcre"

post-patch:
	@${REINPLACE_CMD} -e 's|@LIBTOOL@|${LIBTOOL}|g ; \
		s|	\./libtool|${LIBTOOL}|g ; \
		s|\(DEFS.*\)|\1 -I${LOCALBASE}/include|' \
		${WRKSRC}/src/Makefile.in ${WRKSRC}/pcre/Makefile.in
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's| examples||g' \
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>
