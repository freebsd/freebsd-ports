# Created by: Philippe Casidy <pcasidy@casidy.com>
# $FreeBSD$

PORTNAME=	mtf
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	SUNSITE/system/backup

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unix reader for the Microsoft Tape Format used by NT Backup

LICENSE=	GPLv2

USES=		tar:tgz
ALL_TARGET=	# empty
PLIST_FILES=	bin/mtf
PORTDOCS=	README
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mtf ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
