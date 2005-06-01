# ex:ts=8
# New ports collection makefile for:	LeoArg
# Date created:			Jun 19, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	leoarg
PORTVERSION=	2.2.4
CATEGORIES=	devel
MASTER_SITES=	http://kingleo.home.pages.at/development/cpp/
DISTNAME=	LeoArg-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A class for parsing command lines

USE_GNOME=	gnometarget lthack
USE_INC_LIBTOOL_VER=	13
LIBTOOLFLAGS=	--disable-ltlibs --disable-static
INSTALLS_SHLIB=	yes

PLIST_FILES=	include/LeoArg.hh lib/libLeoArg.so lib/libLeoArg.so.2 \
		${EXAMPLES:S|^|%%EXAMPLESDIR%%/|}
.if !defined(NOPORTDOCS)
EXAMPLES=	Makefile demo.sh leoargmain.cpp
PLIST_DIRS=	%%EXAMPLESDIR%%
PORTDOCS=	*
.endif

MAN3=	LeoArg.3 LeoArg__InvalidOption.3 LeoArg__InvalidSetting.3 \
	LeoArg__Option.3 LeoArg__Setting.3 LeoArg_cpp.3 LeoArg_hh.3 \
	StringUtils_cpp.3 StringUtils_hh.3 namespace_StringUtils.3

post-patch:
.for file in Makefile.in doc/Makefile.in
	@${REINPLACE_CMD} -e 's|^docdir|#docdir|g ; \
		 s| install-data-local||g' ${WRKSRC}/${file}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.* ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/example/${f} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
