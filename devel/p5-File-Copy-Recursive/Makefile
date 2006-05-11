# ex:ts=8
# Ports collection makefile for:	File::Copy::Recursive
# Date created:			Nov 26, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	File-Copy-Recursive
PORTVERSION=	0.22
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl extension for recursively copying files and directories

PERL_CONFIGURE=	yes

MAN3=		File::Copy::Recursive.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	${PERL} -pi -e 's/(mkdir \S+)/$$1, 0755/g' ${WRKSRC}/Recursive.pm
	${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1); $$1/;' ${WRKSRC}/Recursive.pm
	${REINPLACE_CMD} -e '/warnings/d' ${WRKSRC}/Recursive.pm
.endif

.include <bsd.port.post.mk>
