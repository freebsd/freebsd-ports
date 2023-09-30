PORTNAME=	Data-MessagePack-Stream
PORTVERSION=	1.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for yet another messagepack streaming deserializer
WWW=		https://metacpan.org/release/Data-MessagePack-Stream

BROKEN_mips=	fails to build: atomic operations are not found
BROKEN_mips64=	fails to build: atomic operations are not found

BUILD_DEPENDS=	p5-File-Which>=0:sysutils/p5-File-Which \
		p5-Module-Build-XSUtil>=0:devel/p5-Module-Build-XSUtil \
		${RUN_DEPENDS}
LIB_DEPENDS=	libmsgpackc.so:devel/msgpack-c
RUN_DEPENDS=	p5-Data-MessagePack>=0:devel/p5-Data-MessagePack

USES=		localbase:ldflags perl5
USE_PERL5=	modbuild

CFLAGS_aarch64=	-fPIC
CFLAGS_armv7=	-fPIC
CFLAGS_i386=	-fPIC
CFLAGS_powerpc=	-fPIC
CFLAGS_riscv64=	-fPIC
MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/builder/MyBuilder.pm
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/msgpack-3.3.0/

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Data/MessagePack/Stream/Stream.so

.include <bsd.port.mk>
