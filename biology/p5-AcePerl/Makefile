# New ports collection makefile for:	p5-AcePerl
# Date created:		26 July 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	AcePerl
PORTVERSION=	1.89
CATEGORIES=	biology databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Ace
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@p6m7g8.com
COMMENT=	Perl5 interface to the ACEDB genome database system

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		${SITE_PERL}/Cache/Cache.pm:${PORTSDIR}/devel/p5-Cache-Cache
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		ace.pl.1
MAN3=		Ace.3 Ace::Browser::AceSubs.3 Ace::Browser::SearchSubs.3 \
		Ace::Browser::SiteDefs.3 Ace::Graphics::Fk.3 \
		Ace::Graphics::Glyph.3 Ace::Graphics::Glyph::anchored_arrow.3 \
		Ace::Graphics::Glyph::arrow.3 Ace::Graphics::Glyph::box.3 \
		Ace::Graphics::Glyph::dot.3 Ace::Graphics::Glyph::ex.3 \
		Ace::Graphics::Glyph::graded_segments.3 \
		Ace::Graphics::Glyph::group.3 Ace::Graphics::Glyph::line.3 \
		Ace::Graphics::Glyph::primers.3 \
		Ace::Graphics::Glyph::segments.3 Ace::Graphics::Glyph::span.3 \
		Ace::Graphics::Glyph::toomany.3 \
		Ace::Graphics::Glyph::transcript.3 \
		Ace::Graphics::Glyph::triangle.3 \
		Ace::Graphics::GlyphFactory.3 Ace::Graphics::Panel.3 \
		Ace::Graphics::Track.3 Ace::Iterator.3 Ace::Local.3 \
		Ace::Model.3 Ace::Object.3 Ace::Sequence.3 \
		Ace::Sequence::Feature.3 Ace::Sequence::FeatureList.3 \
		Ace::Sequence::GappedAlignment.3 Ace::Sequence::Gene.3 \
		Ace::Sequence::Homol.3 Ace::Sequence::Multi.3 \
		Ace::Sequence::Transcript.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires Perl 5.6.0
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
BROKEN=		Does not compile on amd64 or ia64 (missing -fPIC)
.endif

post-patch:
	@ ${SED} -e 's|XX__CC__XX|${CC}|' < ${FILESDIR}/FREEBSD_DEF \
	  > ${WRKSRC}/acelib/wmake/FREEBSD_DEF

.include <bsd.port.post.mk>
