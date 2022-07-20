PORTNAME=	T2
PORTVERSION=	0.10
PORTREVISION=	3
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SAMV
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Object Relational mapping system

LICENSE=	ART10 GPLv2
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Tangram>=0:devel/p5-Class-Tangram \
		p5-DBI>=0:databases/p5-DBI \
		p5-Set-Object>=0:devel/p5-Set-Object \
		p5-Tangram>=0:databases/p5-Tangram

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e \
		'/eval/s|^|# | ; \
		 /deploy/s|^|#| ; \
		 /print/s|^|#| ; \
		 /NOTESTS/s|^|#|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
