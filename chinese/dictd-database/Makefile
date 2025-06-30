PORTNAME=	dictd-database
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	chinese textproc
MASTER_SITES=	LOCAL/rafan/chinese/
DISTNAME=	dict-zh-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chinese <-> English dictd words database

LICENSE=	GPLv2

DEPRECATED=	Depends on expiring net/dictd
EXPIRATION_DATE=2025-09-30

RUN_DEPENDS=	${LOCALBASE}/sbin/dictd:net/dictd

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
