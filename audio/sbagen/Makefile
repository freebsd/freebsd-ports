# New ports collection makefile for:   sbagen
# Date created:        08 June 2001
# Whom:                greid
#
# $FreeBSD$
#

PORTNAME=	sbagen
PORTVERSION=	1.4.4
CATEGORIES=	audio
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A sequenced binaural wave generator

DOC_FILES=	ChangeLog.txt README.txt SBAGEN.txt TODO.txt focus.txt \
		focus2.txt holosync.txt theory.txt theory2.txt wave.txt

post-patch:
	@${REINPLACE_CMD} -e 's,linux/soundcard.h,sys/soundcard.h,g' \
		${WRKSRC}/sbagen.c

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -DT_LINUX ${PTHREAD_LIBS} -lm sbagen.c -o sbagen)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sbagen ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
