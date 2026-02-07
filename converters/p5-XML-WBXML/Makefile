PORTNAME=	XML-WBXML
PORTVERSION=	0.09
PORTREVISION=	3
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Convert between XML and WBXML using libwbxml2
WWW=		https://metacpan.org/release/XML-WBXML

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

LIB_DEPENDS=	libwbxml2.so:textproc/libwbxml

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/Makefile.PL

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/XML/WBXML/WBXML.so

.include <bsd.port.mk>
