PORTNAME=	SVN-Access
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Perl extension to manipulate SVN Access files
WWW=		https://metacpan.org/release/SVN-Access

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
.if ${WITH_SUBVERSION_VER:U} == LTS
RUN_DEPENDS=	p5-subversion-lts>=0:devel/p5-subversion
.else
RUN_DEPENDS=	p5-subversion>=0:devel/p5-subversion
.endif
RUN_DEPENDS+=	p5-Tie-IxHash>=1.21:devel/p5-Tie-IxHash

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	svnaclmgr.pl

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${INSTALL_SCRIPT} ${PORTEXAMPLES} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
