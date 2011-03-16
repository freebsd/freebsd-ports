# New ports collection makefile for:	nvi-1.79 + perl
# Date created:		18 Feb 1998
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $FreeBSD$
#

PORTNAME=	nvi
PORTVERSION=	1.79
PORTREVISION=	4
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.sleepycat.com/pub/
PKGNAMESUFFIX=	-perl

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A clone of vi/ex, with perl5 linked into

# can't say PATCH_DIST_STRIP=-p1 because contains files outside ${WRKSRC}
PATCH_DIST_ARGS=-d ${WRKSRC}/.. --forward --quiet -E -p0
PATCH_ARGS=	-d ${WRKSRC}/.. --forward --quiet -E -p0
WRKSRC=		${WRKDIR}/${DISTNAME}/build

DEPRECATED=	Distfile is no more available
EXPIRATION_DATE=	2011-05-01

USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OPTFLAG='-D_PATH_SYSEXRC=\"${PREFIX}/etc/vi.exrc\"'
CONFIGURE_ARGS=	--enable-perlinterp --program-prefix=pn
CFLAGS+=	-DPERL_POLLUTE

MAN1=		pnvi.1
MLINKS=		pnvi.1 pnex.1  pnvi.1 pnview.1

.include <bsd.port.pre.mk>

post-depends:
.if exists(${PERL})
PERL_THREADED!=	${PERL} -V | ${GREP} -- -Dusethreads=y || ${TRUE}
.  if ${PERL_THREADED} != ""
IGNORE=		must be built with a NON-threaded Perl
.  endif
.endif

.if ${PERL_LEVEL} >= 501000
BROKEN=		Does not build with perl >= 5.10
.endif

post-patch:
	${LN} -s /usr/include/sys/queue.h ${WRKSRC}/../include/sys/queue_dist.h

.include <bsd.port.post.mk>
