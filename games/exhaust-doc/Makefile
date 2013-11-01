# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	exhaust
PORTVERSION=	1.9.2
CATEGORIES=	games
MASTER_SITES=	http://corewar.co.uk/pihlaja/exhaust/
PKGNAMESUFFIX=	-doc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Redcode simulator easy to embed into applications (docs)

NO_BUILD=	yes

USES=		shebangfix
SHEBANG_FILES=	${WRKSRC}/test.pl

post-patch:
	@${REINPLACE_CMD} -e 's|./\(exhaust\)|\1|g' ${WRKSRC}/test.pl

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in README test.pl
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/src
.for f in asm.c asm.h exhaust.c exhaust.h insn.h pspace.c pspace.h
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/src
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/warriors
.for f in	pin1a.rc pin1a.red pin1b.rc pin1b.red pin2a.rc pin2a.red \
		pin2b.rc pin2b.red ptest1.rc ptest1.red ptest2.rc ptest2.red \
		ptest3.rc ptest3.red ptest4.rc ptest4.red ptest5.rc \
		ptest5.red ptest6.rc ptest6.red validate.rc validate.red
	${INSTALL_DATA} ${WRKSRC}/t/${f} ${STAGEDIR}${DOCSDIR}/warriors
.endfor

.include <bsd.port.mk>
