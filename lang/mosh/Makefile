# New ports collection makefile for:   mosh
# Date created:                2008-07-06
# Whom:                        Katsuji ISHIKAWA <katsuji.ishikawa@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mosh
PORTVERSION=	0.0.7
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	katsuji.ishikawa@gmail.com
COMMENT=	A Fast R6RS Scheme interpreter

PROJECTHOST=	mosh-scheme

GNU_CONFIGURE=	yes
USE_GCC=	4.2+
ONLY_FOR_ARCHS=	i386

SCMS=		all-tests.scm repl.scm tools/psyntax-r6rs/rev10_to_10/psyntax.scm
SS1=		lib/srfi/%3A8.ss lib/srfi/%3A98.ss
SS2=		lib/mosh/test.ss

do-install:
	${MKDIR} ${DATADIR}/lib
	${MKDIR} ${DATADIR}/lib/srfi
	${MKDIR} ${DATADIR}/lib/mosh

.for F in ${SCMS}
	${INSTALL_DATA} ${WRKSRC}/${F} ${DATADIR}/
.endfor

.for F in ${SS1}
	${INSTALL_DATA} ${WRKSRC}/${F} ${DATADIR}/lib/srfi/
.endfor

.for F in ${SS2}
	${INSTALL_DATA} ${WRKSRC}/${F} ${DATADIR}/lib/mosh/
.endfor

	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
