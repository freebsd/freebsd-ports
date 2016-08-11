# Created by: Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	perlconsole
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SUKRIA

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Light program that lets you evaluate Perl code interactively

RUN_DEPENDS=	p5-Term-ReadLine-Gnu>=0:devel/p5-Term-ReadLine-Gnu \
		p5-Module-Refresh>=0:devel/p5-Module-Refresh \
		p5-Lexical-Persistence>=0:devel/p5-Lexical-Persistence \
		p5-B-Keywords>=0:devel/p5-B-Keywords

USES=		perl5 shebangfix
USE_PERL5=	configure
SHEBANG_FILES=	perlconsole
NO_ARCH=	yes

PORTDOCS=	README \
		AUTHORS \
		CHANGES

PLIST_FILES=	bin/perlconsole \
		${SITE_PERL_REL}/PerlConsole/Commands.pm \
		${SITE_PERL_REL}/PerlConsole/Console.pm \
		${SITE_PERL_REL}/PerlConsole/Preferences.pm \
		${SITE_PERL_REL}/PerlConsole.pm

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/PerlConsole/
	${CP} -R ${WRKSRC}/lib/PerlConsole/ \
		${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/PerlConsole/
	${CP} ${WRKSRC}/lib/PerlConsole.pm \
		${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/PerlConsole.pm
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README AUTHORS CHANGES
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
