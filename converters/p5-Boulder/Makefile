# New ports collection makefile for:	p5-Boulder
# Date created:			Di  13 Mär 2001 19:37:25 CET
# Whom:				Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	Boulder
PORTVERSION=	1.20
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Boulder
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=  ${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/XML/Parser/Expat.pm:${PORTSDIR}/textproc/p5-XML-Parser

PERL_CONFIGURE=	YES

MAN3=		Stone::Cursor.3 Boulder::Unigene.3 Boulder::Stream.3 \
		Stone::GB_Sequence.3 Boulder::Store.3 Stone.3 \
		Boulder::Medline.3 Boulder::Swissprot.3 Boulder::XML.3 \
		Boulder::Blast::NCBI.3 Boulder::Blast::WU.3 Boulder::Omim.3 \
		Boulder::Blast.3 Boulder::Genbank.3 Boulder.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
