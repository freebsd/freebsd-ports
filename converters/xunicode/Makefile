# New ports collection makefile for:	XUnicode
# Date created:		25 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	xunicode
PORTVERSION=	0.2.7
CATEGORIES=	converters x11
MASTER_SITES=	http://www.ab.wakwak.com/~tino/jatk/

MAINTAINER=	knu@FreeBSD.org

USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	${PERL} -i -pe 's,/usr/X11R6\b,${X11BASE},g' ${WRKSRC}/MakeInclude

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/libxunicode.a ${PREFIX}/lib/
	${MKDIR} ${PREFIX}/include/xunicode
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${PREFIX}/include/xunicode/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/xunicode/ja/
	${INSTALL_DATA} ${WRKSRC}/README.utf8 ${PREFIX}/share/doc/xunicode/ja/
.endif

.include <bsd.port.mk>
