# Created by: Mathieu Arnold <m@absolight.net>
# $FreeBSD$

PORTNAME=	DateTime
PORTVERSION=	1.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DROLSKY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Date and time object

LICENSE=	ART20

# Do not add p5-DateTime-Format-Strptime>=1.20.00 to TEST_DEPENDS to avoid cyclic dependency in tinderbox
BUILD_DEPENDS=	p5-DateTime-Locale>=0.41:${PORTSDIR}/devel/p5-DateTime-Locale \
		p5-DateTime-TimeZone>=1.09:${PORTSDIR}/devel/p5-DateTime-TimeZone \
		p5-Params-Validate>=0.76:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Try-Tiny>0:${PORTSDIR}/lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal

OPTIONS_DEFINE=	DOCS

USES=		perl5
USE_PERL5=	modbuild

PORTDOCS=	CREDITS Changes TODO

post-install:
	@${STRIP_CMD} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/DateTime/DateTime.so
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
