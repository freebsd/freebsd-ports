# New ports collection makefile for:	p5-DBZ_File
# Date created:				May 26th 2000
# Whom:					Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	DBZ_File
PORTVERSION=	1.1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBZ_File
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	leeym@cae.ce.ntu.edu.tw

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	DEFINE="-I${FILESDIR}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500007
CONFIGURE_ARGS+=	POLLUTE=1
.endif

WRKSRC=		${WRKDIR}/DBZ_File

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		DBZ_File.3

.include <bsd.port.post.mk>
