# Created by: George Reid <greid@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sbagen
PORTVERSION=	1.4.5
CATEGORIES=	audio
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sequenced binaural wave generator

LICENSE=	GPLv2

PORTDOCS=	ChangeLog.txt README.txt SBAGEN.txt TODO.txt focus.txt \
		focus2.txt holosync.txt theory.txt theory2.txt wave.txt

OPTIONS_DEFINE=	DOCS EXAMPLES
NO_STAGE=	yes

.include <bsd.port.options.mk>

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -DT_LINUX -pthread -lm \
		sbagen.c -o sbagen)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sbagen ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
