# New ports collection makefile for:	devel/p5-SVN-Web
# Date created:				Feb 21 2004
# Whom:					CPANPLUS User <cpanplus@example.com>
#
# $FreeBSD$
#

PORTNAME=	SVN-Web
PORTVERSION=	0.47
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	SVN
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@infor.org
COMMENT=	Subversion repository web frontend

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit \
		${SITE_PERL}/${PERL_ARCH}/SVN/Core.pm:${PORTSDIR}/devel/subversion-perl \
		${SITE_PERL}/Text/Diff.pm:${PORTSDIR}/textproc/p5-Text-Diff \
		${SITE_PERL}/XML/RSS.pm:${PORTSDIR}/textproc/p5-XML-RSS \
		${SITE_PERL}/Locale/Maketext/Simple.pm:${PORTSDIR}/devel/p5-Locale-Maketext-Simple \
		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML \
		p5-Cache-Cache>=0:${PORTSDIR}/devel/p5-Cache-Cache \
		p5-Exception-Class>=1.22:${PORTSDIR}/devel/p5-Exception-Class \
		p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-Locale-Maketext-Lexicon>=0:${PORTSDIR}/devel/p5-Locale-Maketext-Lexicon \
		p5-Template-Plugin-Number-Format>=0:${PORTSDIR}/www/p5-Template-Plugin-Number-Format \
		p5-Text-Diff-HTML>=0:${PORTSDIR}/textproc/p5-Text-Diff-HTML \
		p5-HTTP-Server-Simple>=0:${PORTSDIR}/www/p5-HTTP-Server-Simple \
		p5-Template-Plugin-Clickable>=0:${PORTSDIR}/www/p5-Template-Plugin-Clickable \
		p5-Template-Plugin-Clickable-Email>=0:${PORTSDIR}/www/p5-Template-Plugin-Clickable-Email \
		p5-Template-Plugin-Subst>=0:${PORTSDIR}/www/p5-Template-Plugin-Subst
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN1=		svnweb-server.1
MAN3=		SVN::Web.3 \
		SVN::Web::Browse.3 \
		SVN::Web::Checkout.3 \
		SVN::Web::Diff.3 \
		SVN::Web::List.3 \
		SVN::Web::Log.3 \
		SVN::Web::RSS.3 \
		SVN::Web::Revision.3 \
		SVN::Web::Test.3 \
		SVN::Web::View.3 \
		SVN::Web::X.3 \
		SVN::Web::action.3

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/svnweb-install ${PREFIX}/bin
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6 or newer. Please install lang/perl5 or lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
