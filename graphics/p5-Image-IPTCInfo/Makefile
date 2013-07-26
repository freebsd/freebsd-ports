# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Image-IPTCInfo
PORTVERSION=	1.95
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for extracting IPTC image meta-data

PERL_CONFIGURE=	yes
USES=		shebangfix
SHEBANG_FILES=	demo.pl

MAN3=		Image::IPTCInfo.3

post-patch:
	@${RM} -f ${WRKSRC}/._*

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demo_images/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
