# New ports collection makefile for:	mimepp
# Version required:			0.8.0
# Date created:				3 July 1997
# Whom:					Andrey Zakhvatov
#
# $Id$
#

DISTNAME=		mimepp-0.8.0
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	devel/lang/c++

MAINTAINER=		andy@icc.surw.chel.su

WRKSRC=			${WRKDIR}/mimepp-970213
ALL_TARGET=		lib

do-install:
	@ ${INSTALL_DATA} ${WRKSRC}/libmimepp.a ${PREFIX}/lib/libmimepp.a
	@ ${MKDIR} ${PREFIX}/include/mimepp
	@ ${INSTALL_DATA} ${WRKSRC}/mimepp/* ${PREFIX}/include/mimepp
	@ ${MKDIR} ${PREFIX}/share/doc/mimepp
.for file in CPYRIGHT README Tutorial
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/mimepp/${file}
.endfor
	@ ${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/mimepp
	@ ${MKDIR} ${PREFIX}/share/examples/mimepp
.for file in exampl01.cc exampl02.cc exampl03.cc exampl04.cc exampl05.cc attach.cc basicmsg.cc multipar.cc attach.h basicmsg.h multipar.h test01.txt test02.txt test03.txt test04.txt test05.txt 
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/examples/mimepp/${file}
.endfor
	@ ${INSTALL_DATA} files/Makefile ${PREFIX}/share/examples/mimepp

.include <bsd.port.mk>
