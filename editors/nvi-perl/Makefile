# New ports collection makefile for:	nvi-1.79 + perl
# Date created:		18 Feb 1998
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $FreeBSD$
#

PORTNAME=	nvi-perl
PORTVERSION=	1.79
CATEGORIES=	editors
MASTER_SITES=	ftp://sleepy.vwh.net/pub/ \
		ftp://ftp.foretune.co.jp/pub/tools/nvi-m17n/
DISTNAME=	nvi-${PORTVERSION}

MAINTAINER=	itojun@itojun.org

WRKSRC=		${WRKDIR}/${DISTNAME}/build
GNU_CONFIGURE=	yes
USE_PERL5=	yes
# can't say PATCH_DIST_STRIP=-p1 because contains files outside ${WRKSRC}
PATCH_DIST_ARGS=-d ${WRKSRC}/.. --forward --quiet -E -p0
PATCH_ARGS=	-d ${WRKSRC}/.. --forward --quiet -E -p0

CONFIGURE_ENV=	OPTFLAG='-D_PATH_SYSEXRC=\"${PREFIX}/etc/vi.exrc\"'
CONFIGURE_ARGS=	--enable-perlinterp --program-prefix=pn

.include <bsd.port.mk>
