# New ports collection makefile for:	devel/p5-SVN-Web
# Date created:				Feb 21 2004
# Whom:					CPANPLUS User <cpanplus@example.com>
#
# $FreeBSD$
#

PORTNAME=	SVN-Web
PORTVERSION=	0.37
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/C/CL/CLKAO
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@infor.org
COMMENT=	Subversion repository web frontend

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit \
		${SITE_PERL}/${PERL_ARCH}/SVN/Core.pm:${PORTSDIR}/devel/subversion-perl \
		${SITE_PERL}/Text/Diff.pm:${PORTSDIR}/textproc/p5-Text-Diff \
		${SITE_PERL}/XML/RSS.pm:${PORTSDIR}/textproc/p5-XML-RSS \
		${SITE_PERL}/Locale/Maketext/Simple.pm:${PORTSDIR}/devel/p5-Locale-Maketext-Simple \
		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		SVN::Web.3

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/svnweb-install ${PREFIX}/bin

.include <bsd.port.mk>
