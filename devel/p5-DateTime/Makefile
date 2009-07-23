# New ports collection makefile for:	p5-DateTime
# Date created:	   4 mai 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	DateTime
PORTVERSION=	0.50
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	A date and time object

RUN_DEPENDS=	p5-DateTime-Locale>=0.41:${PORTSDIR}/devel/p5-DateTime-Locale \
		p5-DateTime-TimeZone>=0.59:${PORTSDIR}/devel/p5-DateTime-TimeZone \
		p5-Params-Validate>=0.76:${PORTSDIR}/devel/p5-Params-Validate
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DateTime.3 DateTime::Duration.3 \
		DateTime::Helpers.3 DateTime::Infinite.3 DateTime::LeapSecond.3

.if !defined(NOPORTDOCS)
PORTDOCS=	CREDITS Changes TODO

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
