# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Convert-Bencode_XS
PORTVERSION=	0.06
PORTREVISION=	2
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Faster conversions to/from Bencode format

RUN_DEPENDS=	p5-Convert-Bencode>=0:converters/p5-Convert-Bencode

USES=		perl5 shebangfix
SHEBANG_FILES=	extras/*.pl
USE_PERL5=	configure

OPTIONS_DEFINE=	EXAMPLES

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Convert/Bencode_XS/Bencode_XS.so
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/extras/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
