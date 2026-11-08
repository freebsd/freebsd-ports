PORTNAME=	SVN-S4
DISTVERSION=	1.062
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:WSNYDER
PKGNAMEPREFIX=	p5-

MAINTAINER=	gary@hayers.org
COMMENT=	Wrapper for subversion program
WWW=		https://metacpan.org/release/SVN-S4

LICENSE=	ART20 LGPL3
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Config-Tiny>=0:devel/p5-Config-Tiny \
		p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
		p5-IO-AIO>=0:devel/p5-IO-AIO
.if ${WITH_SUBVERSION_VER:U} == LTS
RUN_DEPENDS+=	p5-subversion-lts>=0:devel/p5-subversion
.else
RUN_DEPENDS+=	p5-subversion>=0:devel/p5-subversion
.endif

USES=		perl5
USE_PERL5=	configure

INSTALL_TARGET=	pure_install

NO_ARCH=	yes

.include <bsd.port.mk>
