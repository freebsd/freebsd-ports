# New ports collection makefile for:	mecab
# Date created:		2 April 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	${MECAB_PORTNAME}
PORTVERSION=	${MECAB_PORTVERSION}
CATEGORIES=	japanese textproc
MASTER_SITES=	http://cl.aist-nara.ac.jp/~taku-ku/software/mecab/src/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Yet Another Part-of-Speech and Morphological Analyzer

EXTRACT_DEPENDS=	${NONEXISTENT}:${IPADIC_PORTDIR}:patch

IPADIC_PORTDIR=	${PORTSDIR}/japanese/ipadic

USE_PERL5_BUILD=	yes

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

.include "${.CURDIR}/Makefile.common"

MAN1=		mecab.1

EXAMPLES=	example/*
DOCS=		AUTHORS README doc/*.html doc/*.css

post-extract:
	${LN} -s `cd ${IPADIC_PORTDIR}; ${MAKE} -V WRKSRC` ${WRKSRC}/dic/

post-install:
	${RM} -f ${PREFIX}/lib/libmecab.la
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${EXAMPLESDIR}/
.endfor
	${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
