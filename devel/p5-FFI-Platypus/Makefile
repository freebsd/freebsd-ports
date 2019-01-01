# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	FFI-Platypus
PORTVERSION=	0.59
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Write Perl bindings to non-Perl libraries with FFI

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Config-AutoConf>=0.309:devel/p5-Config-AutoConf \
		${RUN_DEPENDS}
LIB_DEPENDS=	libffi.so:devel/libffi
RUN_DEPENDS=	p5-FFI-CheckLib>=0.05:devel/p5-FFI-CheckLib \
		p5-File-ShareDir>=0:devel/p5-File-ShareDir
TEST_DEPENDS=	p5-Capture-Tiny>=0:devel/p5-Capture-Tiny

USES=		localbase perl5
USE_PERL5=	modbuild

MAKE_ARGS=	extra_compiler_flags="-I${LOCALBASE}/include" \
		extra_linker_flags="-L${LOCALBASE}/lib -lffi"

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/FFI/Platypus/Platypus.so

.include <bsd.port.mk>
