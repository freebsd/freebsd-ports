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

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
.for i in sources/unix.mk taste/unix.mk
	@${REINPLACE_CMD} -e 's|^CFLAGS|#CFLAGS|' ${WRKSRC}/${i}
.endfor
.for i in cplus2 taste taste_cp
	@${RM} -f ${WRKSRC}/${i}/unix.mk.*
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/${PORTNAME}.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	(cd ${WRKSRC}; ${COPYTREE_SHARE} "cplus2 taste taste_cp" \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME})
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/frames; ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/coco.use ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/cocol ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/*.atg ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/*.inp ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
