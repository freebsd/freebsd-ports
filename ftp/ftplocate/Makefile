# New ports collection makefile for:	Ftplocate
# Date created:				7 December 1999
# Whom:					tung@turtle.ee.ncku.edu.tw
#
# $FreeBSD$
#

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

PL_FILES=	install.pl bin/dcollect.pl bin/dindex.pl bin/dsearch.pl \
		bin/flcollect.pl bin/flfilter.pl bin/flhistory.pl \
		bin/flindex.pl bin/flmap.pl bin/flsearch.pl \
		bin/flserv.pl bin/flsummary.pl bin/fltop.pl \
		bin/fltrain.pl bin/flcatsite.pl template/ftplocate

post-extract:
.for f in ${PL_FILES}
	@${PERL} -pi -e 's,/usr/bin/perl,${PERL},' ${WRKSRC}/${f}
.endfor
	@${PERL} -pi -e 's,(/usr/local/www|/usr/local/apache/share),${PREFIX}/www,g' ${WRKSRC}/install.pl
	@${PERL} -pi -e 's,/usr/local/bin/ftplocate,${PREFIX}/bin/ftplocate,g' ${WRKSRC}/install.pl
	@${PERL} -pi -e 's,htdocs,data,g' ${WRKSRC}/install.pl

do-install:
	@${MKDIR} ${PREFIX}/www/data ${PREFIX}/www/cgi-bin
	cd ${WRKSRC}; ${PERL} install.pl -y -c -bsdport

.include <bsd.port.mk>
