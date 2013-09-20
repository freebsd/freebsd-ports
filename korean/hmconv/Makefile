# Created by: Junho CHOI <junho.choi@gmail.com>
# $FreeBSD$

PORTNAME=	hmconv
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	korean mail
MASTER_SITES=	http://ftp.kaist.ac.kr/hangul/code/hmconv/ \
		ftp://ftp.kaist.ac.kr/hangul/code/hmconv/ \
		ftp://ftp.kr.FreeBSD.org/pub/FreeBSD-kr/distfiles/
DISTNAME=	hmconv1.0pl3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hangul code conversion utility for E-mail

PLIST_FILES=	bin/hmailedit bin/hmconv
PORTDOCS=	CHANGES README*
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's|^HEDITOR=.*|HEDITOR=$$EDITOR|' \
	    ${WRKSRC}/hmailedit

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/hmconv ${WRKSRC}/hmconv1.0pl3.c

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/hmailedit ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/hmconv ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${DOCSDIR}
.endif

.include <bsd.port.mk>
