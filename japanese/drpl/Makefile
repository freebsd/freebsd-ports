# New ports collection makefile for:   drpl
# Date created:                18 May 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	drpl
PORTVERSION=	1.04
CATEGORIES=	japanese textproc
MASTER_SITES=	http://www.yk.rim.or.jp/~tomoto/archives/drpl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Replaces words in a Japanese text using dictionaries

USE_PERL5=	yes
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
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/dic/* ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} *.TXT *.man misc/*.htm ${DOCSDIR}
.endif

.include <bsd.port.mk>
