# Created by: Igor Pokrovsky <tiamat@telegraph.spb.ru>
# $FreeBSD$

PORTNAME=	szip
PORTVERSION=	1.12b
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	http://www.compressconsult.com/szip/ \
		ftp://ftp.sai.msu.su/pub/unix/Archivers/
DISTNAME=	sz${PORTVERSION:S/.//}_src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast compression utility

USES=		gmake

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
	${INSTALL_PROGRAM} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/*.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
