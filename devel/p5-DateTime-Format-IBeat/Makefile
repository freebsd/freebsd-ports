# New ports collection makefile for:	p5-DateTime-Format-IBeat
# Date created:	   3 october 2003
# Whom:		   mat
#
# $FreeBSD$
#

PORTNAME=	DateTime-Format-IBeat
PORTVERSION=	0.16.1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DateTime
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(.)$/\1/}

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Format times in .beat notation

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DateTime::Format::IBeat.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
post-patch:
	@${PERL} -pi -e '$$_ = "" if (/use 5.006|use warnings/);' \
		     -e 's/^our ([^\s;]+)/use vars qw($$1); $$1/;' \
		     -e 's/\$$dt->\$$_/$$&()/g;' \
		     ${WRKSRC}/lib/DateTime/Format/IBeat.pm
.endif

.include <bsd.port.post.mk>
