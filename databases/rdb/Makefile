# ports collection makefile for:	rdb
# Version required:			2.6d
# Date created:				2000 Feb. 8
# Whom:					Abel Chow <abel_chow@yahoo.com>
#
# $FreeBSD$
#

DISTNAME=	RDB-2.6d
PKGNAME=	rdb-2.6d
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.rand.org/pub/RDB-hobbs/ \
		ftp://ftp.sunet.se/pub/unix/databases/flat-file/

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/rdb
USE_PERL5=	yes

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
	${MKDIR} ${PREFIX}/share/doc/rdb
.for docfile in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/doc/${docfile} ${PREFIX}/share/doc/rdb
.endfor
.endif

.include <bsd.port.mk>
