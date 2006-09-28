# New ports collection makefile for:	p5-subatom
# Date created:		2006-09-26
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	subatom
PORTVERSION=	0.12
CATEGORIES=	devel
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/H/HD/HDM
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Produce an atom feed from subversion commits

BUILD_DEPENDS=	${SITE_PERL}/XML/Atom/SimpleFeed.pm:${PORTSDIR}/textproc/p5-XML-Atom-SimpleFeed
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes
PLIST_FILES=	bin/subatom

MAN1=		subatom.1

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800	# Inherited from textproc/XML-Atom-SimpleFeed
IGNORE=		requires perl 5.8.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
