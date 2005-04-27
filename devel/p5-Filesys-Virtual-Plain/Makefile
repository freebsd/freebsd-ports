# New ports collection makefile for:	devel/p5-Filesys-Virtual-Plain
# Date created:				05 February 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Filesys-Virtual-Plain
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Filesys
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A Plain virtual filesystem

BUILD_DEPENDS=	${SITE_PERL}/Filesys/Virtual.pm:${PORTSDIR}/devel/p5-Filesys-Virtual
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Filesys::Virtual::Plain.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} <= 500503
post-patch:
	@${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1); $$1/;' ${WRKSRC}/Plain.pm
.endif

.include <bsd.port.post.mk>
