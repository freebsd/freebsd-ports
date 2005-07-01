# New ports collection makefile for:	Data::TreeDumper
# Date created:				1 August 2004
# Whom:					Aaron Dalton <aaron@daltons.ca>
#
# $FreeBSD$
#

PORTNAME=	Data-TreeDumper
PORTVERSION=	0.23
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Data
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@daltons.ca
COMMENT=	Dumps a data structure in a tree fashion

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Term/Size.pm:${PORTSDIR}/devel/p5-Term-Size \
		${SITE_PERL}/Text/Wrap.pm:${PORTSDIR}/textproc/p5-Text-Tabs+Wrap \
		${SITE_PERL}/Class/ISA.pm:${PORTSDIR}/devel/p5-Class-ISA \
		${SITE_PERL}/${PERL_ARCH}/Devel/Size.pm:${PORTSDIR}/devel/p5-Devel-Size
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=		Data::TreeDumper.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -pi -e 's/^our (\S+)/use vars q{$$1};$$1/g;' \
		-e '$$_ = "" if /warnings|5.006/;' \
		-e 's/}\(/}->(/g;' \
		-e '$$_ .= "->" if $$. == 442;' \
		${WRKSRC}/TreeDumper.pm
.endif

.include <bsd.port.post.mk>
