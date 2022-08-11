PORTNAME=	File-MimeInfo
PORTVERSION=	0.33
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Determine file type

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Encode-Locale>=0:converters/p5-Encode-Locale \
		p5-File-BaseDir>=0.03:devel/p5-File-BaseDir \
		p5-File-DesktopEntry>=0.04:devel/p5-File-DesktopEntry

USES=		perl5 shared-mime-info
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
