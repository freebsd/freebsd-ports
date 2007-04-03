# New ports collection makefile for:	p5-DateTime-TimeZone
# Date created:	   4 mai 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	DateTime-TimeZone
PORTVERSION=	0.64
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DateTime
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Time zone object base class and factory

RUN_DEPENDS=	p5-Class-Singleton>=1.03:${PORTSDIR}/devel/p5-Class-Singleton \
		p5-Params-Validate>=0.72:${PORTSDIR}/devel/p5-Params-Validate
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		DateTime::TimeZone.3 DateTime::TimeZone::Floating.3 \
		DateTime::TimeZone::Local.3 DateTime::TimeZone::Local::Unix.3 \
   		DateTime::TimeZone::Local::VMS.3 DateTime::TimeZone::Local::Win32.3 \
	  	DateTime::TimeZone::OffsetOnly.3 DateTime::TimeZone::OlsonDB.3 \
		DateTime::TimeZone::UTC.3 DateTime::TimeZoneCatalog.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires at least Perl 5.6 due to dependencies.  Please install lang/perl5.8 and try again
.endif

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
.endif

.include <bsd.port.post.mk>
