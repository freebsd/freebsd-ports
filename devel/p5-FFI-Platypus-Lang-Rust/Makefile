PORTNAME=	FFI-Platypus-Lang-Rust
PORTVERSION=	0.17
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Platypus Documentation and tools for using Rust
WWW=		https://metacpan.org/pod/FFI::Platypus::Lang::Rust

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-FFI-CheckLib>0:devel/p5-FFI-CheckLib \
		p5-FFI-Platypus>0:devel/p5-FFI-Platypus \
		p5-File-chdir>0:devel/p5-File-chdir \
		p5-File-Which>0:sysutils/p5-File-Which \
		p5-Text-Shellwords>0:textproc/p5-Text-Shellwords

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
