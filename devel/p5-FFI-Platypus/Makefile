# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	FFI-Platypus
PORTVERSION=	0.53
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Write Perl bindings to non-Perl libraries with FFI

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Config-AutoConf>=0.309:devel/p5-Config-AutoConf \
		p5-FFI-CheckLib>=0.05:devel/p5-FFI-CheckLib \
		p5-File-ShareDir>=0:devel/p5-File-ShareDir
LIB_DEPENDS=	libffi.so:devel/libffi
RUN_DEPENDS=	p5-FFI-CheckLib>=0.05:devel/p5-FFI-CheckLib \
		p5-File-ShareDir>=0:devel/p5-File-ShareDir

MAKE_ARGS=	extra_compiler_flags="-I${LOCALBASE}/include" \
		extra_linker_flags="-L${LOCALBASE}/lib -lffi"
USE_PERL5=	modbuild
USES=		localbase perl5

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/FFI/Platypus/Platypus.so

.include <bsd.port.mk>
