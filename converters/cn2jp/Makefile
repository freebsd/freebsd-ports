# New ports collection makefile for:	cn2jp
# Date created:				09 December 2000
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	cn2jp
PORTVERSION=	1.4b
PORTREVISION=	3
CATEGORIES=	converters
MASTER_SITES=	http://w3.sys.es.osaka-u.ac.jp/~seke/software/cn2jp/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	A library for code translation between Chinese and Japanese

INSTALLS_SHLIB=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
PORTDOCS=	README
TEST_PROGRAM=	big2gb/b2g big2jis/b2j gb2big/g2b gb2jis/g2j jis2big/j2b jis2gb/j2g

CFLAGS+=	-fPIC

do-install:
.for test_program in ${TEST_PROGRAM}
	@${INSTALL_PROGRAM} ${WRKSRC}/${test_program} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif
	@${INSTALL_DATA} ${WRKSRC}/libcn2jp.a ${PREFIX}/lib
	@${INSTALL_DATA} ${WRKSRC}/libcn2jp.so ${PREFIX}/lib/libcn2jp.so.1
	@cd ${PREFIX}/lib/; ${LN} -sf libcn2jp.so.1 libcn2jp.so
	@${INSTALL_DATA} ${WRKSRC}/lib/jp-util.h ${PREFIX}/include
	@${INSTALL_DATA} ${WRKSRC}/lib/lang-util.h ${PREFIX}/include

.include <bsd.port.mk>
