# New ports collection makefile for:	p5-File-Slurp
# Date created:				October 17th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	File-Slurp
PORTVERSION=	9999.09
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module for single call read & write file routines

PERL_CONFIGURE=	YES

MAN3=		File::Slurp.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
post-configure:
	cd ${WRKSRC}; \
	${PERL} -pi -e 's|(.*Fcntl.*):seek(.*)|\1\2\nuse POSIX qw(SEEK_SET SEEK_CUR SEEK_END);|; \
			s|.*= O_BINARY.*||;' lib/File/Slurp.pm t/*.t
.endif

.include <bsd.port.post.mk>
