# New ports collection makefile for:	nvi-1.79 + multilingual patch(none)
# Date created:		6 Mar 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $FreeBSD$
#

PORTNAME=	nvi
PORTVERSION=	1.79.19991117
CATEGORIES?=	editors
MASTER_SITES=	ftp://sleepy.vwh.net/pub/\
		ftp://ftp.foretune.co.jp/pub/tools/nvi-m17n/
PKGNAMESUFFIX?=	-m17n
DISTNAME=	nvi-1.79

PATCH_SITES=	ftp://ftp.foretune.co.jp/pub/tools/nvi-m17n/
PATCHFILES=	nvi-1.79.m17n-19991117.diff.gz

MAINTAINER=	itojun@itojun.org

#LIB_DEPENDS=	canna.1:${PORTSDIR}/japanese/Canna

SLAVEDIRS=	chinese/nvi-big5 chinese/nvi-euc-cn chinese/nvi-euc-tw
WRKSRC=		${WRKDIR}/${DISTNAME}/build
GNU_CONFIGURE=	yes
PATCH_DIST_ARGS=-d ${WRKSRC}/.. --forward --quiet -E -p1 -f
CONFIGURE_ENV=	OPTFLAG='-D_PATH_SYSEXRC=\"${PREFIX}/etc/vi.exrc\"'
CONFIGURE_ARGS=	--enable-multibyte --program-prefix=n

post-install:
	@${CP} ${WRKSRC}/../docs.m17n/README.english \
		${PREFIX}/share/vi/
	@${CP} ${WRKSRC}/../docs.m17n/README.japanese \
		${PREFIX}/share/vi/

.include <bsd.port.mk>
