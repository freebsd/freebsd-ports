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

USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*.txt

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,more logfile,cat logfile,' \
			  -e "s,^CFLAGS.*,CFLAGS= ${CFLAGS}," \
		${WRKSRC}/makefile

do-build:
	${GMAKE} -C ${WRKDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
