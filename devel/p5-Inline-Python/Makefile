# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Inline-Python
PORTVERSION=	0.51
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Write Perl Subroutines in Python

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Inline>=0.46:devel/p5-Inline
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Proc-ProcessTable>=0.53:devel/p5-Proc-ProcessTable \
		p5-Test-Deep>=0:devel/p5-Test-Deep

USE_PERL5=	configure
USES=		perl5 python
CONFIGURE_ENV=	INLINE_PYTHON_EXECUTABLE="${PYTHON_CMD}"

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Inline/Python/Python.so

.include <bsd.port.mk>
