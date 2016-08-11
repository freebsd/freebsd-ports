# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Pod-Usage
PORTVERSION=	1.69
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Print a usage message from embedded pod documentation

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-podlators>=4:textproc/p5-podlators
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

post-patch:
# Do not conflict with lang/perl5.*
	@${REINPLACE_CMD} -e 's| pod2usage||' ${WRKSRC}/Makefile.PL
	@${RM} ${WRKSRC}/scripts/pod2usage.PL

.include <bsd.port.mk>
