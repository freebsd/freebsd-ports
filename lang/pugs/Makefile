# New ports collection makefile for:	lang/pugs
# Date created:				Mon Mar 14 16:01:08 CST 2005
# Whom:					clsung
#
# $FreeBSD$
#

PORTNAME=	pugs
PORTVERSION=	6.28.0
CATEGORIES=	lang devel perl5
MASTER_SITES=   ${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=     clsung
DISTNAME=       Perl6-Pugs-${PORTVERSION}.r22035

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A Perl6 Implementation

RUN_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		${SITE_PERL}/${PERL_ARCH}/Term/ReadLine/Gnu.pm:${PORTSDIR}/devel/p5-ReadLine-Gnu \
		${SITE_PERL}/Pugs/Emitter/Perl6/Perl5.pm:${PORTSDIR}/lang/p5-v6 \
    		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
    		p5-Data-Bind>=0.28:${PORTSDIR}/devel/p5-Data-Bind \
    		p5-Devel-Caller>=0.10:${PORTSDIR}/devel/p5-Devel-Caller \
    		p5-Module-Compile>=0.17:${PORTSDIR}/devel/p5-Module-Compile \
    		p5-Moose>=0.10:${PORTSDIR}/devel/p5-Moose \
		p5-File-Slurp>0:${PORTSDIR}/devel/p5-File-Slurp \
    		p5-Pugs-Compiler-Rule>=0.17:${PORTSDIR}/lang/p5-Pugs-Compiler-Rule \
    		p5-Sub-Multi>=0:${PORTSDIR}/devel/p5-Sub-Multi
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple

BROKEN=		does not build

PERL_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/Perl6-Pugs-${PORTVERSION}

MAN3=		Inline::Pugs.3 \
		Perl6::API.3 \
		Perl6::API::Math::Basic.3 \
		Perl6::API::Scalar.3 \
		Perl6::API::macros.3 \
		Perl6::Doc.3 \
		Perl6::FAQ::Capture.3 \
		Perl6::FAQ::FUD.3 \
		Perl6::Overview.3 \
		Perl6::Overview::Control.3 \
		Perl6::Overview::Data.3 \
		Perl6::Overview::File.3 \
		Perl6::Overview::Functions.3 \
		Perl6::Overview::Object.3 \
		Perl6::Overview::Operator.3 \
		Perl6::Overview::Reduce.3 \
		Perl6::Overview::Rule.3 \
		Perl6::Overview::Smartmatch.3 \
		Perl6::Overview::Subroutine.3 \
		Perl6::Overview::Variable.3 \
		Perl6::Perl5::Differences.3 \
		Perl6::Perl5::Docfinder.3 \
		Perl6::Pugs.3 \
		Perl6::Spec.3 \
		Perl6::Spec::Block.3 \
		Perl6::Spec::CPAN.3 \
		Perl6::Spec::Concurrency.3 \
		Perl6::Spec::Documentation.3 \
		Perl6::Spec::Functions.3 \
		Perl6::Spec::IO.3 \
		Perl6::Spec::Module.3 \
		Perl6::Spec::Object.3 \
		Perl6::Spec::Operator.3 \
		Perl6::Spec::Overload.3 \
		Perl6::Spec::Overview.3 \
		Perl6::Spec::Package.3 \
		Perl6::Spec::Rule.3 \
		Perl6::Spec::Structure.3 \
		Perl6::Spec::Subroutine.3 \
		Perl6::Spec::Syntax.3 \
		Perl6::Tutorial.3

.include <bsd.port.pre.mk>

post-configure:
	@${REINPLACE_CMD} -e '/^INSTALLPRIVLIB/s,${PREFIX}/lib,${PREFIX}/lib/perl6,;' \
		-e '/^INSTALLARCHLIB/s,${PREFIX}/lib,${PREFIX}/lib/perl6/mach,' \
		${WRKSRC}/Makefile

.if !defined(NOPORTDOCS)
EXDIR=		${WRKSRC}/examples
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} -R ${EXDIR}/ ${EXAMPLESDIR}
	@${FIND} -s ${EXAMPLESDIR} -type f | \
		${SED} -e 's|^${PREFIX}/||' >> ${TMPPLIST}
	@${FIND} -d ${EXAMPLESDIR} -type d | \
		${SED} -e 's|^${PREFIX}/|@dirrm |' >> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
