# New ports collection makefile for:	lang/pugs
# Date created:				Mon Mar 14 16:01:08 CST 2005
# Whom:					clsung
#
# $FreeBSD$
#

PORTNAME=	pugs
PORTVERSION=	6.2.12
CATEGORIES=	lang devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Perl6
DISTNAME=	Perl6-Pugs-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A Perl6 Implementation

BROKEN=		fails to deinstall cleanly

RUN_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		${SITE_PERL}/${PERL_ARCH}/Term/ReadLine/Gnu.pm:${PORTSDIR}/devel/p5-ReadLine-Gnu
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=		Perl6::Pugs.3 \
		Inline::Pugs.3 \
		Pugs::Doc::Run.3 Pugs::Doc::Hack.3

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

.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.x or later
.endif

.include <bsd.port.post.mk>
