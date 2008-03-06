# New ports collection makefile for:	perlconsole
# Date created:				9 October 2007
# Whom:					Philippe Audeoud <jadawin@tuxaco.net>
#
# $FreeBSD$
#

PORTNAME=	perlconsole
PORTVERSION=	0.4
CATEGORIES=	devel
MASTER_SITES=	http://www.cpan.org/modules/by-module/Test/SUKRIA/

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	A light program that lets you evaluate Perl code interactively

RUN_DEPENDS=	${BASEP}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long \
		${BASEP}/${PERL_ARCH}/Term/ReadLine/Gnu.pm:${PORTSDIR}/devel/p5-ReadLine-Gnu \
		${BASEP}/Module/Refresh.pm:${PORTSDIR}/devel/p5-Module-Refresh \
		${BASEP}/Lexical/Persistence.pm:${PORTSDIR}/devel/p5-Lexical-Persistence \
		${BASEP}/B/Keywords.pm:${PORTSDIR}/devel/p5-B-Keywords

BASEP=		${SITE_PERL}

USE_PERL5=	yes
PERL_CONFIGURE=	5.8.0+

PORTDOCS=	README \
		AUTHORS \
		CHANGES

PLIST_FILES=	bin/perlconsole \
		lib/perl5/${PERL_VER}/PerlConsole/Commands.pm \
		lib/perl5/${PERL_VER}/PerlConsole/Console.pm \
		lib/perl5/${PERL_VER}/PerlConsole/Preferences.pm \
		lib/perl5/${PERL_VER}/PerlConsole.pm

PLIST_DIRS=	lib/perl5/${PERL_VER}/PerlConsole

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README AUTHORS CHANGES
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	${MKDIR} ${PREFIX}/lib/perl5/${PERL_VER}/PerlConsole/
	${CP} -R ${WRKSRC}/lib/PerlConsole/ \
		${PREFIX}/lib/perl5/${PERL_VER}/PerlConsole/
	${CP} ${WRKSRC}/lib/PerlConsole.pm \
		${PREFIX}/lib/perl5/${PERL_VER}/PerlConsole.pm
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
