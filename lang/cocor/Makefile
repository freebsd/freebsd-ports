# Created by: Guy Antony Halse <guy@rucus.ru.za.za>
# $FreeBSD$

PORTNAME=	cocor
PORTVERSION=	1.7
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.psg.com/pub/modula-2/coco/ \
		ftp://ftp.ssw.uni-linz.ac.at/pub/Coco/C/ \
		http://www.scifac.ru.ac.za/coco/
DISTNAME=	${PORTNAME}c${PORTVERSION:S/.//}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compiler generator that combines the functionality of lex and yacc

NO_WRKSUBDIR=	yes

USES=		dos2unix
MAKE_ENV=	CRFRAMES="${WRKSRC}/frames"
MAKEFILE=	unix.mk
ALL_TARGET=	all1

MAN1=		${PORTNAME}.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
.for i in sources/unix.mk taste/unix.mk
	@${REINPLACE_CMD} -e 's|^CFLAGS|#CFLAGS|' ${WRKSRC}/${i}
.endfor
.for i in cplus2 taste taste_cp
	@${RM} -f ${WRKSRC}/${i}/unix.mk.*
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/${PORTNAME}.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}
.for i in cplus2 taste taste_cp
	@(cd ${WRKSRC}; ${COPYTREE_SHARE} ${i} ${PREFIX}/lib/${PORTNAME})
.endfor
	@${MKDIR} ${DATADIR}
	@(cd ${WRKSRC}/frames; ${COPYTREE_SHARE} . ${DATADIR})
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/coco.use ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/cocol ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/*.atg ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/*.inp ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
