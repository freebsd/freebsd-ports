# Created by: Joerg Wunsch <joerg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sketch
PORTVERSION=	0.3.7
CATEGORIES=	graphics
MASTER_SITES=	http://www.frontiernet.net/~eugene.ressler/
EXTRACT_SUFX=	.tgz

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	3D Scene Description Translator

LICENSE=	GPLv3

MAKEFILE=	makefile
ALL_TARGET=
USES=		gmake perl5
USE_PERL5=	build
USE_DOS2UNIX=	yes

PLIST_FILES=	bin/sketch

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	readme updates.htm

DOCSRCDIR2=	${WRKSRC}/Doc/sketch
DOCSDIR2=	${DOCSDIR}/Doc/sketch
DOC_FILES2=	*

DOCSRCDIR3=	${WRKSRC}/Doc
DOCSDIR3=	${DOCSDIR}/Doc
DOC_FILES3=	*.eps *.pdf *.png *.sk *.txt *.tex *.texi
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
PORTEXAMPLES=	*.sk
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/^CC =.*//' \
		-e 's/$$(CC)/$$(CC) $$(CFLAGS)/g' \
		-e 's/^YACC =.*/YACC = yacc/' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
	@${MKDIR} ${DOCSDIR3}
	${INSTALL_DATA} ${DOC_FILES3:S|^|${DOCSRCDIR3}/|} ${DOCSDIR3}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/Data && ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
