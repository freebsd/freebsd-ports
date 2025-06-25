PORTNAME=	szip
PORTVERSION=	1.12b
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	http://www.compressconsult.com/szip/ \
		ftp://ftp.sai.msu.su/pub/unix/Archivers/
DISTNAME=	sz${PORTVERSION:S/.//}_src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast compression utility
WWW=		http://www.compressconsult.com/szip/

LICENSE=	SZ
LICENSE_NAME=	Szip License
LICENSE_FILE=	${WRKSRC}/readme.txt
LICENSE_PERMS=	auto-accept

MAKEFILE=	makefile

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*.txt

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,more logfile,cat logfile,' \
			  -e "s,^CFLAGS.*,CFLAGS= ${CFLAGS}," \
		${WRKSRC}/makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
