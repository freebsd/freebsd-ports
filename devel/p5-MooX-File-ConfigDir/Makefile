PORTNAME=	MooX-File-ConfigDir
PORTVERSION=	0.008
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Moo eXtension for File::ConfigDir

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/ARTISTIC-1.0
LICENSE_FILE_GPLv1+ =	${WRKSRC}/GPL-1

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-ConfigDir>=0.018:devel/p5-File-ConfigDir \
		p5-Moo>=1.003000:devel/p5-Moo

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
