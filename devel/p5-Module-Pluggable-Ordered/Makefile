# New ports collection makefile for:	p5-Module-Pluggable-Ordered
# Date created:		2004-08-29
# Whom:			Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Module-Pluggable-Ordered
PORTVERSION=	1.3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Module
PKGNAMEPREFIX=	p5-

MAINTAINER=	apeiron@comcast.net
COMMENT=	Call module plugins in a specified order

BUILD_DEPENDS=	${SITE_PERL}/Module/Pluggable.pm:${PORTSDIR}/devel/p5-Module-Pluggable \
		${SITE_PERL}/UNIVERSAL/require.pm:${PORTSDIR}/devel/p5-UNIVERSAL-exports
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Module::Pluggable::Ordered.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500503
post-patch:
	${PERL} -pi -e '$$_ = "" if /use 5.006;/;' \
		${WRKSRC}/Makefile.PL
	${PERL} -pi -e '$$_ = "" if /use 5.006;/;' \
		    -e '$$_ = "" if /use warnings/;' \
		    -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1); $$1/;' \
		    -e 's/(->\$$order_name) /$$1\(\) /g;' \
                ${WRKSRC}/Ordered.pm
.endif
.include <bsd.port.post.mk>
