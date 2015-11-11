# Created by: Joerg Wunsch <joerg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sketch
PORTVERSION=	0.3.7
CATEGORIES=	graphics
MASTER_SITES=	http://www.frontiernet.net/~eugene.ressler/

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	3D Scene Description Translator

LICENSE=	GPLv3

BROKEN=		Checksum and size mismatch
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison

MAKEFILE=	makefile
ALL_TARGET=
USES=		dos2unix gmake perl5 tar:tgz
USE_PERL5=	build

PLIST_FILES=	bin/sketch

OPTIONS_DEFINE=	DOCS EXAMPLES

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
		-e 's/^YACC =.*/YACC = bison/' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin/

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}/${DOCSDIR}
	@${MKDIR} ${STAGEDIR}/${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}/${DOCSDIR2}
	@${MKDIR} ${STAGEDIR}/${DOCSDIR3}
	${INSTALL_DATA} ${DOC_FILES3:S|^|${DOCSRCDIR3}/|} ${STAGEDIR}/${DOCSDIR3}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}/${EXAMPLESDIR}
	cd ${WRKSRC}/Data && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}/${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
