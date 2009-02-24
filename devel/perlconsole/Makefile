# New ports collection makefile for:	perlconsole
# Date created:				9 October 2007
# Whom:					Philippe Audeoud <jadawin@tuxaco.net>
#
# $FreeBSD$
#

PORTNAME=	perlconsole
PORTVERSION=	0.4
CATEGORIES=	devel
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/S/SU/SUKRIA

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	A light program that lets you evaluate Perl code interactively

RUN_DEPENDS=	${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long \
		${SITE_PERL}/${PERL_ARCH}/Term/ReadLine/Gnu.pm:${PORTSDIR}/devel/p5-ReadLine-Gnu \
		${SITE_PERL}/Module/Refresh.pm:${PORTSDIR}/devel/p5-Module-Refresh \
		${SITE_PERL}/Lexical/Persistence.pm:${PORTSDIR}/devel/p5-Lexical-Persistence \
		${SITE_PERL}/B/Keywords.pm:${PORTSDIR}/devel/p5-B-Keywords

USE_PERL5=	yes
PERL_CONFIGURE=	5.8.0+

PORTDOCS=	README \
		AUTHORS \
		CHANGES

PLIST_FILES=	bin/perlconsole \
		${SITE_PERL_REL}/PerlConsole/Commands.pm \
		${SITE_PERL_REL}/PerlConsole/Console.pm \
		${SITE_PERL_REL}/PerlConsole/Preferences.pm \
		${SITE_PERL_REL}/PerlConsole.pm

PLIST_DIRS=	${SITE_PERL_REL}/PerlConsole

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README AUTHORS CHANGES
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	${MKDIR} ${PREFIX}/${SITE_PERL_REL}/PerlConsole/
	${CP} -R ${WRKSRC}/lib/PerlConsole/ \
		${PREFIX}/${SITE_PERL_REL}/PerlConsole/
	${CP} ${WRKSRC}/lib/PerlConsole.pm \
		${PREFIX}/${SITE_PERL_REL}/PerlConsole.pm
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
