# New ports collection makefile for:	chasen
# Date created:		21 October 1998
# Whom:			kuriyama
#
# $NetBSD: Makefile,v 1.2 1999/06/07 09:54:39 sakamoto Exp $
# $FreeBSD$
#

PORTNAME=	chasen
PORTVERSION=	2.02
PORTREVISION=	3
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.aist-nara.ac.jp/pub/lab/nlp/tools/chasen/
DISTNAME=	${PORTNAME}-sys${PORTVERSION}-ipadic2.1

MAINTAINER=	knu@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKE_ARGS=	NOPROFILE=true
INSTALLS_SHLIB=	yes

DOCS_EN=	README doc/manual.pdf doc/manual.tex
DOCS_JA=	CHANGES README.ja doc/manual-j.pdf doc/manual-j.tex

post-patch:
	${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}/lib/Makefile

post-build:
	@${ECHO_MSG} "Making dictionaries"
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} dic

post-install:
	${MKDIR} ${PREFIX}/include/chasen
	@cd ${WRKSRC}/lib; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} install
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/chasen/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/chasen/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/chasen/ja/
.endfor
.endif

.include <bsd.port.mk>
