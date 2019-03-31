# Created by: Tomokazu ISHII <t-ishii@tryplanet.com>
# $FreeBSD$

PORTNAME=	ftpfind
PORTVERSION=	0.996
CATEGORIES=	ftp
MASTER_SITES=	http://hp.vector.co.jp/authors/VA013366/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Find directory or file on FTP server

PLIST_FILES=	bin/ftpfind

USES=		shebangfix
SHEBANG_FILES=	ftpfind

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ftpfind ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
