PORTNAME=	ppmd
PORTVERSION=	20050811
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Fast archiver with good compression ratio
WWW=		https://packages.debian.org/unstable/utils/ppmd/

LICENSE=	PD

ONLY_FOR_ARCHS=	i386

USES=		cpe

CPE_VENDOR=	ppmd_project

PLIST_FILES=	bin/ppmd \
		share/man/man1/ppmd.1.gz
PORTDOCS=	read_me.txt

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
