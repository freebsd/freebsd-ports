# New ports collection makefile for:	mecab
# Date created:		2 April 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	mecab
PORTVERSION=	0.74
CATEGORIES=	japanese textproc
MASTER_SITES=	http://cl.aist-nara.ac.jp/~taku-ku/software/mecab/src/ \
		http://chasen.aist-nara.ac.jp/stable/ipadic/:dic
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${IPADIC_DISTNAME}${EXTRACT_SUFX}:dic

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Yet Another Part-of-Speech and Morphological Analyzer

IPADIC_DISTNAME=	ipadic-2.5.0

USE_PERL=	yes

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

MAN1=		mecab.1

EXAMPLES=	example/*
DOCS=		AUTHORS README doc/*.html doc/*.css

post-extract:
	${LN} -s ${WRKDIR}/${IPADIC_DISTNAME} ${WRKSRC}/dic/

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
