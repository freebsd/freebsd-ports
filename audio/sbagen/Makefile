# New ports collection makefile for:   sbagen
# Date created:        08 June 2001
# Whom:                greid
#
# $FreeBSD$
#

PORTNAME=	sbagen
PORTVERSION=	1.4.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A sequenced binaural wave generator

PORTDOCS=	COPYING.txt ChangeLog.txt README.txt SBAGEN.txt \
		focus.txt holosync.txt mk-msvc.txt readme-windows.txt \
		theory.txt theory2.txt wave.txt

post-patch:
	@${REINPLACE_CMD} -e 's,linux/soundcard.h,sys/soundcard.h,g' \
		${WRKSRC}/sbagen.c

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -DT_LINUX ${PTHREAD_LIBS} -lm sbagen.c -o sbagen)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sbagen ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.sbg ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for D in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$D ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
