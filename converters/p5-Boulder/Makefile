# New ports collection makefile for:	p5-Boulder
# Date created:			Di  13 Mär 2001 19:37:25 CET
# Whom:				Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	Boulder
PORTVERSION=	1.30
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Boulder
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	An API for hierarchical tag/value structures

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser/Expat.pm:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Boulder.3 \
		Boulder::Blast.3 \
		Boulder::Blast::NCBI.3 \
		Boulder::Blast::WU.3 \
		Boulder::Genbank.3 \
		Boulder::Medline.3 \
		Boulder::LocusLink.3 \
		Boulder::Omim.3 \
		Boulder::Store.3 \
		Boulder::Stream.3 \
		Boulder::String.3 \
		Boulder::Swissprot.3 \
		Boulder::Unigene.3 \
		Boulder::XML.3 \
		Stone.3 \
		Stone::Cursor.3 \
		Stone::GB_Sequence.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
