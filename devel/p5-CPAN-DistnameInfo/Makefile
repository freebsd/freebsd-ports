# New ports collection makefile for:	p5-CPAN-DistnameInfo
# Date created:				Mar 27 2004
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$

PORTNAME=	CPAN-DistnameInfo
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Extract distribution name and version from a CPAN filename

PERL_CONFIGURE=	yes

MAN3=		CPAN::DistnameInfo.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} <= 500503
# make PREFIX-clean under perl 5.005_03
post-configure:
	@${PERL} -pi -e 's,/usr/local/,\$$(PREFIX)/,g' ${WRKSRC}/Makefile
.endif

.include <bsd.port.post.mk>
