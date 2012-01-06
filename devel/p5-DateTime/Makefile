# New ports collection makefile for:	p5-DateTime
# Date created:	   4 mai 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	DateTime
PORTVERSION=	0.71
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DROLSKY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A date and time object

BUILD_DEPENDS=	p5-DateTime-Locale>=0.41:${PORTSDIR}/devel/p5-DateTime-Locale \
		p5-DateTime-TimeZone>=1.09:${PORTSDIR}/devel/p5-DateTime-TimeZone \
		p5-Math-Round>=0:${PORTSDIR}/math/p5-Math-Round \
		p5-Params-Validate>=0.76:${PORTSDIR}/devel/p5-Params-Validate
RUN_DEPENDS:=	${BUILD_DEPENDS}

# Do not add p5-DateTime-Format-Strptime>=1.20.00 to avoid cyclic dependency in tinderbox
TEST_DEPENDS=	p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal

PERL_MODBUILD=	yes

MAN3=		DateTime.3 DateTime::Duration.3 \
		DateTime::Infinite.3 \
		DateTime::LeapSecond.3

.if !defined(NOPORTDOCS)
PORTDOCS=	CREDITS Changes TODO

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
TEST_DEPENDS+=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
