# New ports collection makefile for:	nvi-1.79 + multilingual patch(none)
# Date created:		6 Mar 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $FreeBSD$
#

PORTNAME=	nvi
PORTVERSION=	1.79.20040401
PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES?=	editors
MASTER_SITES=	ftp://ftp.sleepycat.com/pub/
PKGNAMESUFFIX?=	-m17n
DISTNAME=	nvi-1.79

PATCH_SITES=	ftp://ftp.foretune.co.jp/pub/tools/nvi-m17n/
PATCHFILES=	nvi-1.79.m17n-20040401.diff.gz

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	A clone of vi/ex, with multilingual patch, no default settings

PATCH_DIST_ARGS=	-d ${WRKSRC}/.. --forward --quiet -E -p0 -f
WRKSRC=		${WRKDIR}/${DISTNAME}/build

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OPTFLAG='-D_PATH_SYSEXRC=\"${PREFIX}/etc/vi.exrc\"'
CONFIGURE_ARGS?=	--enable-multibyte --program-prefix=n

MAN1=		nvi.1
MLINKS=		nvi.1 nex.1  nvi.1 nview.1

SLAVEDIRS=	chinese/nvi-big5 chinese/nvi-euc-cn chinese/nvi-euc-tw

.include <bsd.port.pre.mk>

post-patch:
	${LN} -s /usr/include/sys/queue.h ${WRKSRC}/../include/sys/queue_dist.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/../docs.m17n/README.english \
		${PREFIX}/share/vi/
	${INSTALL_DATA} ${WRKSRC}/../docs.m17n/README.japanese \
		 ${PREFIX}/share/vi/

.include <bsd.port.post.mk>
