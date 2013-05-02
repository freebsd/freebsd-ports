# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CPAN-Changes
PORTVERSION=	0.20
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Read and write CPAN Changes files

PERL_CONFIGURE=	yes

MAN1=	tidy_changelog.1
MAN3=	CPAN::Changes.3 \
	CPAN::Changes::Release.3 \
	CPAN::Changes::Spec.3 \
	Test::CPAN::Changes.3 \

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501200
BUILD_DEPENDS+=	p5-version>=0.79:${PORTSDIR}/devel/p5-version
RUN_DEPENDS+=	p5-version>=0.79:${PORTSDIR}/devel/p5-version
.endif

.include <bsd.port.post.mk>
