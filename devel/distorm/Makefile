# New ports collection makefile for:	distorm
# Date created:				13 May 2008
# Whom:					bf <bf2006a@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	distorm
PORTVERSION=	1.7.30
CATEGORIES=	devel
MASTER_SITES=	http://www.ragestorm.net/distorm/
DISTNAME=	${PORTNAME}64-pkg${PORTVERSION}

MAINTAINER=	bf1783@gmail.com
COMMENT=	Fast x86 and x86-64 disassembler library

USE_BZIP2=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/distorm64/build/linux
ALL_TARGET=	clib
PLIST_FILES=	bin/disasm lib/libdistorm64.a lib/libdistorm64.so

.ifndef(NOPORTDOCS)
PORTDOCS=	distorm.html qa.txt vol1.html vol2.html
.endif

do-install:
	( cd ${WRKSRC} && ${INSTALL_PROGRAM} libdistorm64.a libdistorm64.so ${PREFIX}/lib \
	&& ${INSTALL_PROGRAM} disasm ${PREFIX}/bin )

.ifndef(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKDIR}/distorm64/doc/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
