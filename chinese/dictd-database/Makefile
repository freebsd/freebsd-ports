# New ports collection makefile for:	dict-zh
# Date created:		25 Oct 1999
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	dictd-database
PORTVERSION=	1.6
CATEGORIES=	chinese textproc
MASTER_SITES=	ftp://freebsd.csie.ntu.edu.tw/users/rafan/ \
		ftp://freebsd.sinica.edu.tw/pub/statue/dictd-database/
DISTNAME=	dict-zh-${PORTVERSION}

MAINTAINER=	rafan@infor.org
COMMENT=	A Chinese <-> English dictd words database

RUN_DEPENDS=	${LOCALBASE}/sbin/dictd:${PORTSDIR}/net/dictd

NO_BUILD=	yes

MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKSRC}/pkg-message

DICTFILES=	cedict pydict moecomp netterm

do-install:
	${SED} 's|%%PREFIX%%|${PREFIX}|g' ${MSG_FILE} > ${PKGMESSAGE}
	@${MKDIR} ${PREFIX}/lib/dict
	for f in ${DICTFILES}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$${f}.dict.dz ${PREFIX}/lib/dict; \
	  ${INSTALL_DATA} ${WRKSRC}/$${f}.index ${PREFIX}/lib/dict; \
	done

post-install:
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 502110
RUN_DEPENDS+=	${LOCALBASE}/share/locale/zh_TW.UTF-8/LC_CTYPE:${PORTSDIR}/misc/utf8locale
.endif

.include <bsd.port.post.mk>
