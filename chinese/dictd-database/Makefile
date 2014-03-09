# Created by: Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
# $FreeBSD$

PORTNAME=	dictd-database
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	chinese textproc
MASTER_SITES=	LOCAL/rafan/chinese/ \
		ftp://freebsd.sinica.edu.tw/pub/statue/dictd-database/
DISTNAME=	dict-zh-${PORTVERSION}

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Chinese <-> English dictd words database

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/sbin/dictd:${PORTSDIR}/net/dictd

NO_BUILD=	yes
SUB_FILES=	pkg-message

DICTFILES=	cedict pydict moecomp netterm

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/dict
	for f in ${DICTFILES}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$${f}.dict.dz ${STAGEDIR}${PREFIX}/lib/dict; \
	  ${INSTALL_DATA} ${WRKSRC}/$${f}.index ${STAGEDIR}${PREFIX}/lib/dict; \
	done

.include <bsd.port.mk>
