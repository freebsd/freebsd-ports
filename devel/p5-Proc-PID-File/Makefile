# New ports collection makefile for:	p5-Proc-PID-File
# Date created:				Apr 13 2004
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$

PORTNAME=	Proc-PID-File
PORTVERSION=	1.24
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Proc
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A module to manage process id files

PERL_CONFIGURE=	yes

MAN3=		Proc::PID::File.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} <= 500503
post-patch:
	@${PERL} -pi -e '$$_ = "" if /no warnings/' ${WRKSRC}/File.pm

# make PREFIX-clean under perl 5.005_03
post-configure:
	@${PERL} -pi -e 's,/usr/local/,\$$(PREFIX)/,g' ${WRKSRC}/Makefile
.endif

.include <bsd.port.post.mk>
