# New ports collection makefile for:	POE-Component-EasyDBI
# Date created:		31 Jan 2004
# Whom:			Zach Thompson <lin-chi@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-EasyDBI
PORTVERSION=	1.00
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	POE Component for simplified DBI usage

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${SITE_PERL}/Error.pm:${PORTSDIR}/lang/p5-Error
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::EasyDBI.3 \
		POE::Component::EasyDBI::SubProcess.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
post-patch:
	@${PERL} -pi -e 's/^our\s+(.VERSION).+?Revision:\s+(\S+).+$$/use vars qw($$1);\n$$1 = q($$2);/o;' \
			-e '$$_ = "" if /(no|use) warnings/;' \
			${WRKSRC}/lib/POE/Component/EasyDBI.pm \
			${WRKSRC}/lib/POE/Component/EasyDBI/SubProcess.pm
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
.endif

.include <bsd.port.post.mk>
