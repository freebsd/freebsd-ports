# New ports collection makefile for:	Term::ProgressBar
# Date created:				30 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=		Term-ProgressBar
PORTVERSION=		2.01
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/F/FL/FLUFFY
PKGNAMEPREFIX=		p5-

MAINTAINER=		svenasse@polaris.ca

BUILD_DEPENDS=		${SITE_PERL}/Class/MethodMaker.pm:${PORTSDIR}/devel/p5-Class-MethodMaker \
			${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey
RUN_DEPENDS=		${BUILD_DEPENDS}

SITE_PERL=		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
EXAMPLESDIR?=		${PREFIX}/share/examples/${PORTNAME}
PERL_CONFIGURE=		yes

MAN3=			Term::ProgressBar.3
MANPREFIX=		${PREFIX}/lib/perl5/${PERL_VERSION}

pre-fetch:
	@${ECHO} ""
	@${ECHO} "This port requires a newer version of perl than what is available"
	@${ECHO} "in the base system.  You may have to install the lang/perl5 port."
	@${ECHO} ""

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
