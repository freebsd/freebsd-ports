PORTNAME=	Test-OpenLDAP
PORTVERSION=	0.72
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to creates temp instance of slapd to run tests against
WWW=		https://metacpan.org/release/Test-OpenLDAP

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Data-UUID>0:devel/p5-Data-UUID \
		p5-perl-ldap>0:net/p5-perl-ldap

USES=		ldap:server perl5
USE_PERL5=	configure

CONFIGURE_ENV=	PATH=${PATH}:${PREFIX}/libexec

NO_ARCH=	yes

.include <bsd.port.mk>
