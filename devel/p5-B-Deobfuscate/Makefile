# New ports collection makefile for:	p5-B-Deobfuscate
# Date created:	   7 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	B-Deobfuscate
PORTVERSION=	0.10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	B
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Extension to B::Deparse for use in de-obfuscating source code

RUN_DEPENDS=	${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML \
		${SITE_PERL}/B/Keywords.pm:${PORTSDIR}/devel/p5-B-Keywords
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		B::Deobfuscate.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -pi -e 's/^our (\$$VERSION)/use vars qw($$1); $$1/;' \
		     -e '$$_ = "" if /use warnings/;' \
		     -e 's/\[:digit:\]/0-9/g; s/\[:lower:\]/a-z/g;' \
		     -e 's/, \$$dict_file/. \$$dict_file/;' \
		 ${WRKSRC}/lib/B/Deobfuscate.pm
.endif

.include <bsd.port.post.mk>
