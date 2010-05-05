# New ports collection makefile for:	SVN::Look
# Date created:		2009-01-27
# Whom:			Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SVN-Look
PORTVERSION=	0.18
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	A caching wrapper aroung the svnlook command

BUILD_DEPENDS=	${LOCALBASE}/bin/svnlook:${PORTSDIR}/devel/subversion
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		SVN::Look.3

.include <bsd.port.mk>
