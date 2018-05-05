# Created by: Abel Chow <abel_chow@yahoo.com>
# $FreeBSD$

PORTNAME=	rdb
PORTVERSION=	2.6d
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.sunet.se/pub/unix/databases/flat-file/RDB/
DISTNAME=	RDB-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast, portable, relational database management system

BROKEN=		No public distfiles
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2018-06-06

USES=		perl5 shebangfix
SHEBANG_FILES=	${BINFILES}
NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/rdb

BINFILES=	column compute dataent etbl headchg jointbl lst2tbl \
		mergetbl mktbl ptbl rdb rdbt repair reporttbl row search \
		sorttbl subtotal summ tbl2lst uniqtbl valid

PORTDOCS=	RDB.pln.noM.gz RDB.ps.gz rdbi.doc

OPTIONS_DEFINE=	DOCS

do-install:
.for binfile in ${BINFILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${binfile} ${STAGEDIR}${PREFIX}/bin
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docfile in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${docfile} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
