# New ports collection makefile for:	p5-SVG-Metadata
# Date created:		2005-03-13
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SVG-Metadata
PORTVERSION=	0.25
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	SVG
PKGNAMEPREFIX=	p5-

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Perl module to capture metadata info about an SVG file

BUILD_DEPENDS=	xml_grep:${PORTSDIR}/textproc/p5-XML-Twig
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	svg_validate.1 svg_annotate.1
MAN3=	SVG::Metadata.3

post-patch:
	${RM} -f ${WRKSRC}/lib/SVG/Metadata.pm.orig

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	This port requires perl 5.6.0 or later, Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
