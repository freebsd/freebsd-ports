PORTNAME=	POE-Loop-Glib
PORTVERSION=	0.038
PORTREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:APOCAL
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Bridge that supports Glib event loop from POE
WWW=		https://metacpan.org/release/POE-Loop-Glib

LICENSE=	GPLv2

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-POE>=1.288:devel/p5-POE \
		p5-Glib>=1.222:devel/p5-Glib

USES=		perl5 shebangfix
SHEBANG_FILES=	examples/gtk2_counter.pl
USE_PERL5=	modbuild
NO_ARCH=	yes

OPTIONS_DEFINE=	EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
