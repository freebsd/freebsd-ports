# New ports collection makefile for:	cocor
# Date Created: 			24 March 2002
# Whom: 				Guy Antony Halse <guy@rucus.ru.za.za>
#
# $FreeBSD$
#

PORTNAME=	cocor
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.scifac.ru.ac.za/coco/
DISTNAME=	cocorc17
EXTRACT_SUFX=	.tgz

MAINTAINER=	guy-ezmlm@rucus.ru.ac.za
COMMENT=	A compiler generator that combines the functionality of lex and yacc

WRKSRC=		${WRKDIR}
ALL_TARGET=	all1
MAKE_ENV+=	CRFRAMES=${WRKSRC}/frames
USE_GMAKE=	yes
CFLAGS+=	-I${WRKSRC}/cplus2
PLIST_SUB+=	FRAMES=${CRFRAMES}
CRFRAMES?=	${PREFIX}/lib/cocor

MAN1=		cocor.1

post-extract:
	${LN} -s ${WRKSRC}/unix.mk ${WRKSRC}/Makefile

pre-patch:
	uudecode -p ${WRKSRC}/dos2unix.uue > ${WRKSRC}/dos2unix.sh
	${CHMOD} +x ${WRKSRC}/dos2unix.sh
	cd ${WRKSRC} && ./dos2unix.sh unix.mk && ${MAKE} -f unix.mk dos2unix

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cocor ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/cocor.1 ${PREFIX}/man/man1
	${MKDIR} -m 755 ${CRFRAMES}
	${CP} -r ${WRKSRC}/frames/* ${CRFRAMES} && \
		${FIND} ${CRFRAMES} -type f -exec ${CHMOD} 644 {} \; && \
		${FIND} ${CRFRAMES} -type d -exec ${CHMOD} 755 {} \;
	${MKDIR} -m 755 ${PREFIX}/share/cocor
.for i in samples cplus2 taste taste_cp docs
	${CP} -r ${WRKSRC}/${i} ${PREFIX}/share/cocor
.endfor
	${FIND} ${PREFIX}/share/cocor -type f -exec ${CHMOD} 644 {} \; && \
	${FIND} ${PREFIX}/share/cocor -type d -exec ${CHMOD} 755 {} \;

.include <bsd.port.mk>
