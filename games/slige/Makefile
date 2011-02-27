# New ports collection makefile for:	slige
# Date created:				2006-10-09
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	slige
PORTVERSION=	485
CATEGORIES=	games
MASTER_SITES=	http://members.aol.com/dmchess/
DISTNAME=	${PORTNAME}src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DOOM level generator

USE_ZIP=	yes
NO_WRKSUBDIR=	yes

OPTIONS=	PATCH "Use patch to make rooms more open and puzzly" off

.include <bsd.port.pre.mk>

.if defined(WITH_PATCH)
PATCH_SITES=	http://www.samiam.org/
PATCHFILES=	${PORTNAME}.patch
.endif

post-extract:
	@cd ${WRKSRC} && for f in *; do \
	    ${MV} $$f `echo $$f | ${TR} "[:upper:]" "[:lower:]"`; done

post-patch:
	@${REINPLACE_CMD} -e '$$d' ${WRKSRC}/slige.c

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${PORTNAME} slige.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/*.cfg ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
