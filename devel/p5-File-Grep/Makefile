# New ports collection makefile for:	File-Grep
# Date created:			08 May 2004
# Whom:				Xavier Beaudouin <kiwi@oav.net>
#
# $FreeBSD$

PORTNAME=	File-Grep
PORTVERSION=	0.01
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-

MAINTAINER=	kiwi@oav.net
COMMENT=	Perl Module that Find matches to a pattern in files or function

PERL_CONFIGURE=	yes

MAN3=		File::Grep.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -pi -e 's/^our (\S+)/use vars qw{$$1};$$1/g' ${WRKSRC}/Grep.pm
.endif

.include <bsd.port.post.mk>
