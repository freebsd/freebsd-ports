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

SITE_PERL6_REL=	lib/perl6

MAN3=		Perl6::Pugs.3 \
		Inline::Pugs.3

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

.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.x or later
.endif

.include <bsd.port.post.mk>
