# New ports collection makefile for:	nvi-1.79 + multilingual patch(none)
# Version required:	1.79
# Date created:		6 Mar 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $FreeBSD$
#


DISTNAME=	nvi-1.79
PKGNAME?=	nvi-m17n-1.79.19990331
CATEGORIES=	editors
MASTER_SITES=	ftp://sleepy.vwh.net/pub/\
		ftp://ftp.foretune.co.jp/pub/tools/nvi-m17n/

PATCH_SITES=	ftp://ftp.foretune.co.jp/pub/tools/nvi-m17n/
PATCHFILES=	nvi-1.79.m17n-19990331.diff.gz

MAINTAINER=	itojun@itojun.org

#LIB_DEPENDS=	canna.1:${PORTSDIR}/japanese/Canna

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
