# New ports collection makefile for:	p5-DateTime-TimeZone
# Date created:	   4 mai 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	DateTime-TimeZone
PORTVERSION=	1.18
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Time zone object base class and factory

RUN_DEPENDS=	p5-Class-Singleton>=1.03:${PORTSDIR}/devel/p5-Class-Singleton \
		p5-Params-Validate>=0.72:${PORTSDIR}/devel/p5-Params-Validate
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		DateTime::TimeZone.3 DateTime::TimeZone::Floating.3 \
		DateTime::TimeZone::Local.3 DateTime::TimeZone::Local::Unix.3 \
   		DateTime::TimeZone::Local::VMS.3 DateTime::TimeZone::Local::Win32.3 \
	  	DateTime::TimeZone::OffsetOnly.3 DateTime::TimeZone::OlsonDB.3 \
		DateTime::TimeZone::UTC.3 DateTime::TimeZone::Catalog.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500806
RUN_DEPENDS+=	p5-PathTools>=3:${PORTSDIR}/devel/p5-PathTools
.endif

.include <bsd.port.post.mk>
