# New ports collection makefile for:   drpl
# Date created:                18 May 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	drpl
PORTVERSION=	1.04
CATEGORIES=	japanese textproc perl5
MASTER_SITES=	http://www.yk.rim.or.jp/~tomoto/archives/drpl/

MAINTAINER=	fuyuki@mj.0038.net

USE_PERL5=	yes

DICSDIR=	${PREFIX}/share/${PORTNAME}
SCRIPTS=	drpl revdic

post-patch:
.for i in ${SCRIPTS}
	${PERL} -pi -e 's,/usr/local/bin/perl,${PERL},' ${WRKSRC}/${i}
.endfor

do-build:
.for i in maruyaex osaka yarumaex
	${PERL} ${WRKSRC}/drpl -u -D ${WRKSRC}/dic/${i}.dic /dev/null
.endfor

do-install:
	cd ${WRKSRC}; ${INSTALL_SCRIPT} ${SCRIPTS} ${PREFIX}/bin
	${MKDIR} ${DICSDIR}
	${INSTALL_DATA} ${WRKSRC}/dic/* ${DICSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} *.TXT *.man misc/*.htm ${DOCSDIR}
.endif

.include <bsd.port.mk>
