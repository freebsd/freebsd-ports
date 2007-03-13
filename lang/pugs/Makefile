# New ports collection makefile for:	lang/pugs
# Date created:				Mon Mar 14 16:01:08 CST 2005
# Whom:					clsung
#
# $FreeBSD$
#

PORTNAME=	pugs
PORTVERSION=	6.2.13
CATEGORIES=	lang devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Perl6
DISTNAME=	Perl6-Pugs-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A Perl6 Implementation

RUN_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		${SITE_PERL}/${PERL_ARCH}/Term/ReadLine/Gnu.pm:${PORTSDIR}/devel/p5-ReadLine-Gnu \
		${SITE_PERL}/Pugs/Emitter/Perl6/Perl5.pm:${PORTSDIR}/lang/p5-v6 \
    		p5-Data-Bind>=0.28:${PORTSDIR}/devel/p5-Data-Bind \
    		p5-Devel-Caller>=0.10:${PORTSDIR}/devel/p5-Devel-Caller \
    		p5-Module-Compile>=0.17:${PORTSDIR}/devel/p5-Module-Compile \
    		p5-Moose>=0.10:${PORTSDIR}/devel/p5-Moose \
    		p5-Pugs-Compiler-Rule>=0.17:${PORTSDIR}/lang/p5-Pugs-Compiler-Rule \
    		p5-Sub-Multi>=0:${PORTSDIR}/devel/p5-Sub-Multi
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=		Perl6::Pugs.3 \
		Inline::Pugs.3

SITE_PERL6_REL=	lib/perl6
PERL6_MANPREFIX= ${TARGETDIR}/${SITE_PERL6_REL}/site_perl/auto/pugs/perl5
SITE_PERL6_MAN3=	Class::Rebless.3 \
			PIL2JS::JSPM.3 \
			Pugs::Compiler::Perl6.3 \
			Pugs::Compiler::Regex.3 \
			Pugs::Compiler::RegexPerl5.3 \
			Pugs::Compiler::Rule.3 \
			Pugs::Compiler::Token.3 \
			Pugs::Compiler::compile_p6grammar-token.3 \
			Pugs::Compiler::compile_p6grammar.3 \
			Pugs::Emitter::Perl6::Perl5.3 \
			Pugs::Grammar::Precedence.3 \
			Pugs::Runtime::Capture.3 \
			Pugs::Runtime::Match.3 \
			Pugs::Runtime::Perl6.3 \
			v6.3
_MANPAGES+=     ${SITE_PERL6_MAN3:S%^%${PERL6_MANPREFIX}/man3/%}
PLIST_SUB=      SITE_PERL6_REL=${SITE_PERL6_REL}

.include <bsd.port.pre.mk>

post-configure:
	@${REINPLACE_CMD} -e '/^INSTALLPRIVLIB/s,${PREFIX}/lib,${TARGETDIR}/lib/perl6,;' \
		-e '/^INSTALLARCHLIB/s,${PREFIX}/lib,${TARGETDIR}/lib/perl6/mach,' \
		${WRKSRC}/Makefile

.if !defined(NOPORTDOCS)
EXDIR=		${WRKSRC}/examples
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} -R ${EXDIR}/ ${EXAMPLESDIR}
	@${FIND} -s ${EXAMPLESDIR} -type f | \
		${SED} -e 's|^${TARGETDIR}/||' >> ${TMPPLIST}
	@${FIND} -d ${EXAMPLESDIR} -type d | \
		${SED} -e 's|^${TARGETDIR}/|@dirrm |' >> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
