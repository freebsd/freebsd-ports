# New ports collection makefile for:	devel/p5-SVN-ACL
# Date created:				Jan  2006
# Whom:					clsung
#
# $FreeBSD$
#

PORTNAME=	SVN-ACL
PORTVERSION=	0.02
PORTREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A simple ACL frontend for subversion

BUILD_DEPENDS=	\
		p5-subversion>=0:${PORTSDIR}/devel/p5-subversion \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		SVN::ACL.3

.include <bsd.port.mk>
