# Created by: Mathieu Arnold <m@absolight.net>
# $FreeBSD$

PORTNAME=	DateTime
PORTVERSION=	0.78
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DROLSKY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A date and time object

LICENSE=	ART20

# Do not add p5-DateTime-Format-Strptime>=1.20.00 to TEST_DEPENDS to avoid cyclic dependency in tinderbox
BUILD_DEPENDS=	p5-DateTime-Locale>=0.41:${PORTSDIR}/devel/p5-DateTime-Locale \
		p5-DateTime-TimeZone>=1.09:${PORTSDIR}/devel/p5-DateTime-TimeZone \
		p5-Params-Validate>=0.76:${PORTSDIR}/devel/p5-Params-Validate
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal

OPTIONS_DEFINE=	DOCS

PERL_MODBUILD=	yes

MAN3=		DateTime.3 DateTime::Duration.3 \
		DateTime::Infinite.3 \
		DateTime::LeapSecond.3
PORTDOCS=	CREDITS Changes TODO

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}/
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
