# New Ports Collection Makefile for:	p5-File-Modified
# Date created:				2004-07-08
# Whom:					Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	File-Modified
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for checking intelligently if files have changed

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		File::Modified.3

.include <bsd.port.pre.mk>

post-patch:
	${PERL} -pi -e 's/\r\n/\n/;' -e 's/^use warnings;//' ${WRKSRC}/Modified.pm

.include <bsd.port.post.mk>
