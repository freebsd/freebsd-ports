# New ports collection makefile for:	p5-Mac-PropertyList
# Date created:	24 December 2010
# Whom:		Nobutaka Mantani <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Mac-PropertyList
PORTVERSION=	1.38
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	A Perl extension for parsing Mac OS X property lists

LICENSE_COMB=	dual
LICENSE=	ART10 GPLv1

BUILD_DEPENDS=	p5-XML-Entities>=0:${PORTSDIR}/textproc/p5-XML-Entities
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Mac::PropertyList.3 \
	Mac::PropertyList::ReadBinary.3 \
	Mac::PropertyList::WriteBinary.3

.include <bsd.port.mk>
