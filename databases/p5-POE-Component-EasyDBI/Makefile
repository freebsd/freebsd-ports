# New ports collection makefile for:	POE-Component-EasyDBI
# Date created:		31 Jan 2004
# Whom:			Zach Thompson <lin-chi@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-EasyDBI
PORTVERSION=	1.09
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	POE Component for simplified DBI usage

RUN_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${SITE_PERL}/Error.pm:${PORTSDIR}/lang/p5-Error
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools

PERL_CONFIGURE=	yes

MAN3=		POE::Component::EasyDBI.3 \
		POE::Component::EasyDBI::SubProcess.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137

post-patch:
	@${PERL} -pi -e 's/^our\s+(\$$\S+)/use vars qw($$1); $$1/g;' \
		-e 'undef $$_ if /^\s*(no|use) warnings/o;' \
		${WRKSRC}/lib/POE/Component/EasyDBI.pm \
		${WRKSRC}/lib/POE/Component/EasyDBI/SubProcess.pm

post-configure:
	@${PERL} -pi -e 's/-I\S+PERL\S+ //g if m{PERL_DL_NONLAZY}' ${WRKSRC}/Makefile
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
.endif

.include <bsd.port.post.mk>
