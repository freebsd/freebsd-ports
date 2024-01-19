PORTNAME=	ppmd
PORTVERSION=	20050811
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Fast archiver with good compression ratio
WWW=		https://packages.debian.org/unstable/utils/ppmd/

LICENSE=	PD

USES=		cpe

CPE_VENDOR=	ppmd_project

PORTDOCS=	read_me.txt
PLIST_FILES=	bin/ppmd share/man/man1/ppmd.1.gz

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
