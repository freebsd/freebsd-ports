# New ports collection makefile for:	mimepp
# Version required:			1.0
# Date created:				3 July 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		mimepp-1.0
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	devel/lang/c++

MAINTAINER=		andy@icc.surw.chel.su

MAKEFILE=		makefile.unx
ALL_TARGET=		lib

do-install:
	@ ${INSTALL_DATA} ${WRKSRC}/libmimepp.a ${PREFIX}/lib
	@ ${MKDIR} ${PREFIX}/include/mimepp
.for file in address.h addrlist.h binhex.h body.h bodypart.h boyermor.h config.h datetime.h debug.h disptype.h entity.h enum.h field.h fieldbdy.h group.h headers.h mailbox.h mboxlist.h mechansm.h mediatyp.h message.h mimepp.h msgcmp.h msgid.h nntp.h param.h pop.h protocol.h smtp.h string.h text.h token.h utility.h uuencode.h
	@ ${INSTALL_DATA} ${WRKSRC}/mimepp/${file} ${PREFIX}/include/mimepp
.endfor
	@ ${MKDIR} ${PREFIX}/share/doc/mimepp
.for file in CPYRIGHT LICENSE README Tutorial
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/mimepp
.endfor
	@ ${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/mimepp
	@ ${MKDIR} ${PREFIX}/share/examples/mimepp
	@ ${INSTALL_DATA} ${FILESDIR}/Makefile ${PREFIX}/share/examples/mimepp
.for file in attach.cpp attach.h basicmsg.cpp basicmsg.h exampl01.cpp exampl01.txt exampl02.cpp exampl02.txt exampl03.cpp exampl03.txt exampl04.cpp exampl04.txt exampl05.cpp exampl05.txt multipar.cpp multipar.h
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/examples/mimepp
.endfor

.include <bsd.port.mk>
