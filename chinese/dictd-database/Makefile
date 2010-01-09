# New ports collection makefile for:	dict-zh
# Date created:		25 Oct 1999
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	dictd-database
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	chinese textproc
MASTER_SITES=	LOCAL/rafan/chinese/ \
		ftp://freebsd.sinica.edu.tw/pub/statue/dictd-database/
DISTNAME=	dict-zh-${PORTVERSION}

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	A Chinese <-> English dictd words database

RUN_DEPENDS=	${LOCALBASE}/sbin/dictd:${PORTSDIR}/net/dictd

NO_BUILD=	yes
SUB_FILES=	pkg-message

DICTFILES=	cedict pydict moecomp netterm

do-install:
	@${MKDIR} ${PREFIX}/lib/dict
	for f in ${DICTFILES}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$${f}.dict.dz ${PREFIX}/lib/dict; \
	  ${INSTALL_DATA} ${WRKSRC}/$${f}.index ${PREFIX}/lib/dict; \
	done

post-install:
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}

.include <bsd.port.mk>
