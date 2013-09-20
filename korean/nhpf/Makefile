# Created by: Junho CHOI <junho.choi@gmail.com>
# $FreeBSD$

PORTNAME=	nhpf
PORTVERSION=	1.42
PORTREVISION=	1
CATEGORIES=	korean www
MASTER_SITES=	ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hangul Printing Filter for Netscape with embedded font

PLIST_FILES=	bin/nhpf
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nhpf ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
