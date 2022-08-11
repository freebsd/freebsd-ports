PORTNAME=	CPAN-SQLite
PORTVERSION=	0.199
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RKOBES
PKGNAMEPREFIX=	p5-

MAINTAINER=	eg@fbsd.lt
COMMENT=	Search CPAN using a SQLite database

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite	\
		p5-File-HomeDir>=0:devel/p5-File-HomeDir \
		p5-CPAN-DistnameInfo>=0:devel/p5-CPAN-DistnameInfo \
		p5-libwww>=0:www/p5-libwww \
		p5-PathTools>=0:devel/p5-PathTools

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
