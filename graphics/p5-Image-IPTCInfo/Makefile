# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Image-IPTCInfo
PORTVERSION=	1.95
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for extracting IPTC image meta-data

USES=		perl5 shebangfix
USE_PERL5=	configure
SHEBANG_FILES=	demo.pl

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${RM} ${WRKSRC}/._*

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demo_images/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
