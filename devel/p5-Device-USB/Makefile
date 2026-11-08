PORTNAME=	Device-USB
DISTVERSION=	0.35
PORTREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GWADEJ
PKGNAMEPREFIX=	p5-

MAINTAINER=	josh.carroll@gmail.com
COMMENT=	Perl wrapper for libusb
WWW=		https://metacpan.org/release/Device-USB

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

DEPRECATED=	Upstream advises it as deprecated and noo longer suitable for use
EXPIRATION_DATE=	2026-11-10

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Inline>=0:devel/p5-Inline \
		p5-Inline-C>=0:devel/p5-Inline-C

USES=		perl5
USE_PERL5=	configure

MAKE_JOBS_UNSAFE=yes

post-patch:
	@${REINPLACE_CMD} -e 's|dump_usb.pl|lib/Device/&|' ${WRKSRC}/MANIFEST
	@${MV} ${WRKSRC}/dump_usb.pl ${WRKSRC}/lib/Device/

.include <bsd.port.mk>
