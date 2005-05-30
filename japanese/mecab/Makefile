# New ports collection makefile for:	mecab
# Date created:		2 April 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	${MECAB_PORTNAME}
PORTVERSION=	${MECAB_PORTVERSION}
CATEGORIES=	japanese textproc
MASTER_SITES=	http://chasen.org/~taku/software/mecab/src/ \
		http://chasen.naist.jp/stable/ipadic/:ipadic
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${IPADIC_DISTNAME}${EXTRACT_SUFX}:ipadic

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Yet Another Part-of-Speech and Morphological Analyzer

IPADIC_DISTNAME=	ipadic-2.5.1

USE_PERL5_BUILD=	yes
USE_REINPLACE=		yes

USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}"

.include "${.CURDIR}/Makefile.common"

MAN1=		mecab.1

EXAMPLES=	example/*
DOCS=		AUTHORS README doc/*.html doc/*.css

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		"Does not compile on sparc64"
.endif

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

post-patch:
	${REINPLACE_CMD} -e 's/-lpthread/${PTHREAD_LIBS}/g' \
			 -e 's/-O3/${CFLAGS}/' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.post.mk>
