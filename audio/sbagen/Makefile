# New ports collection makefile for:   sbagen
# Date created:        08 June 2001
# Whom:                greid
#
# $FreeBSD$
#

PORTNAME=	sbagen
PORTVERSION=	1.0.8
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A sequenced binaural wave generator

SHAREFILES=	t-alpha t-beta t-calm t-calm2 t-delta t-focus t-focus-1 \
		t-focus-2 t-focus2 t-mix1 t-seqall t-test10 t-test10b \
		t-test10c t-theta t-truth-other t-wave-1 t-wave-2 \
		prog-990102 prog-990103 prog-990104 prog-990105 prog-990106 \
		prog-990107 prog-990108 prog-990111 prog-990112 prog-990118 \
		prog-990209 prog-chakras-1 prog-scan-1 prog-spin-1 \
		prog-tape-1 prog-tape-1-hp prog-tape-2 prog-tape-3

DOCFILES=	sbagen.txt theory.txt theory2.txt

USE_REINPLACE=	yes

pre-patch:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/sbagen.c

post-patch:
.for F in ${SHAREFILES}
	@${REINPLACE_CMD} -e 's,/bin/bash,/bin/sh,g' ${WRKSRC}/$F
.endfor

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} sbagen.c -o sbagen -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sbagen ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/sbagen
.for S in ${SHAREFILES}
	${INSTALL_SCRIPT} ${WRKSRC}/$S ${PREFIX}/share/sbagen
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/sbagen
.for D in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/$D ${PREFIX}/share/doc/sbagen
.endfor
.endif

.include <bsd.port.mk>
