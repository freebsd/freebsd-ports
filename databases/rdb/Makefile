# Created by: Abel Chow <abel_chow@yahoo.com>
# $FreeBSD$

PORTNAME=	rdb
PORTVERSION=	2.6d
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.sunet.se/pub/unix/databases/flat-file/RDB/
DISTNAME=	RDB-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A fast, portable, relational database management system

WRKSRC=		${WRKDIR}/rdb
USES=		perl5

BINFILES=	column compute dataent etbl headchg jointbl lst2tbl \
		mergetbl mktbl ptbl rdb rdbt repair reporttbl row search \
		sorttbl subtotal summ tbl2lst uniqtbl valid

DOCFILES=	RDB.pln.noM.gz RDB.ps.gz rdbi.doc

do-build:
	cd ${WRKSRC}; \
	${PERL} -pi -e 's|^\#\! /usr/bin/perl|\#\!${PERL}|g' ${BINFILES}

do-install:
.for binfile in ${BINFILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${binfile} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${DOCSDIR}
.for docfile in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/doc/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
