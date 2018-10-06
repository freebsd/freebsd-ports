# Created by: James E Keenan <jkeenan@cpan.org>
# $FreeBSD$

PORTNAME=	CPAN-Testers-Common-Client
PORTVERSION=	0.14
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jkeenan@cpan.org
COMMENT=	Common class for CPAN::Testers clients

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Capture-Tiny>=0:devel/p5-Capture-Tiny \
		p5-Config-Perl-V>=0:devel/p5-Config-Perl-V \
		p5-Devel-Platform-Info>=0:devel/p5-Devel-Platform-Info \
		p5-File-HomeDir>=0.58:devel/p5-File-HomeDir \
		p5-Probe-Perl>=0:sysutils/p5-Probe-Perl

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	DOCS

PORTDOCS=	Changes README.md

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
