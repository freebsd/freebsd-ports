# New ports collection makefile for:	Ftplocate
# Version required:			1.50
# Date created:				7 December 1999
# Whom:					tung@turtle.ee.ncku.edu.tw
#
# $FreeBSD$
#

DISTNAME=	ftplocate-1.50
CATEGORIES=	ftp www
MASTER_SITES=	ftp://ftp.ee.ncku.edu.tw/pub/

MAINTAINER=	tung@turtle.ee.ncku.edu.tw

RUN_DEPENDS+=	glimpse:${PORTSDIR}/textproc/glimpse

USE_PERL5=	yes
NO_BUILD=	yes

do-install:
	${INSTALL} -d ${PREFIX}/www/cgi-bin/ftplocate \
		${PREFIX}/www/cgi-bin/ftplocate/index \
		${PREFIX}/www/cgi-bin/ftplocate/desc \
		${PREFIX}/www/data
	${INSTALL} -o nobody -g nobody -m 755 -d ${PREFIX}/www/cgi-bin/ftplocate/cache
	cd ${WRKSRC}; \
	${INSTALL_DATA} \
		README README.zhtw fl.english fl.zhtw \
		${PREFIX}/www/cgi-bin/ftplocate ;\
	${INSTALL} -c -m 644 \
		fl.config fl.share \
		${PREFIX}/www/cgi-bin/ftplocate ;\
	${INSTALL_SCRIPT} \
		dcollect.pl dindex.pl flcollect.pl flindex.pl indexer.sh \
		flfilter.pl flsearch.pl dsearch.pl flserv.pl flhistory.pl \
		${PREFIX}/www/cgi-bin/ftplocate ;\
	${INSTALL_DATA} \
		flhelp.html flhelp.zhtw.html \
		${PREFIX}/www/data ;\
	${INSTALL_SCRIPT}  ftplocate ${PREFIX}/bin/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
