# Created by: George Reid <greid@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sbagen
PORTVERSION=	1.4.5
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sequenced binaural wave generator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USES=		tar:tgz

PORTDOCS=	ChangeLog.txt README.txt SBAGEN.txt TODO.txt focus.txt \
		focus2.txt holosync.txt theory.txt theory2.txt wave.txt

OPTIONS_DEFINE=	DOCS EXAMPLES

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -DT_LINUX -pthread -lm \
		sbagen.c -o sbagen)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sbagen ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
