# Created by: tung@turtle.ee.ncku.edu.tw
# $FreeBSD$

PORTNAME=	ftplocate
PORTVERSION=	2.02
CATEGORIES=	ftp www
MASTER_SITES=	http://turtle.ee.ncku.edu.tw/ftplocate/download/

MAINTAINER=	tung@turtle.ee.ncku.edu.tw
COMMENT=	A ftp search engine supporting filename and description search

RUN_DEPENDS=	glimpse:${PORTSDIR}/textproc/glimpse \
		unzip:${PORTSDIR}/archivers/unzip

USE_PERL5=	yes
NO_BUILD=	yes

USES=		shebangfix
SHEBANG_FILES=	bin/*.pl template/ftplocate

post-extract:
	@${REINPLACE_CMD} -i '' -e 's|/usr/local/www|${PREFIX}/www|' \
		-e 's|/usr/local/apache/share|${PREFIX}/www|' ${WRKSRC}/install.pl
	@${REINPLACE_CMD} -i '' -e 's|/usr/local/bin/ftplocate|${PREFIX}/bin/ftplocate|' \
		-e 's|htdocs|data|' -e 's|/usr/bin/perl|${PERL}|' ${WRKSRC}/install.pl

do-install:
	@${MKDIR} ${PREFIX}/www/data ${PREFIX}/www/cgi-bin
	cd ${WRKSRC}; ${PERL} install.pl -y -c -bsdport

.include <bsd.port.mk>
