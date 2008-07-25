# New ports collection makefile for:	szip
# Date created:		15 January 2002
# Whom:			Igor Pokrovsky <tiamat@telegraph.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	szip
PORTVERSION=	1.12b
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	http://www.compressconsult.com/szip/ \
		ftp://ftp.sai.msu.su/pub/unix/Archivers/
DISTNAME=	sz${PORTVERSION:S/.//}_src

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A fast compression utility

USE_GMAKE=	yes

WRKSRC=		${WRKDIR}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*.txt

post-patch:
	@${REINPLACE_CMD} -e 's,more logfile,cat logfile,' \
			  -e "s,^CFLAGS.*,CFLAGS= ${CFLAGS}," \
		${WRKSRC}/makefile

do-build:
	${GMAKE} -C ${WRKDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
