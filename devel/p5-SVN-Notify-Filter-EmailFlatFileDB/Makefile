# New ports collection makefile for:	SVN-Notify-Filter-EmailFlatFileDB
# Date created:		2008-07-21
# Whom:			Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SVN-Notify-Filter-EmailFlatFileDB
PORTVERSION=	1.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Converts account names to email address based on a flat-file database

RUN_DEPENDS=	p5-SVN-Notify>=2.72:${PORTSDIR}/devel/p5-SVN-Notify
BUILD_DEPENDS=	p5-SVN-Notify>=2.72:${PORTSDIR}/devel/p5-SVN-Notify

PERL_CONFIGURE=	yes

MAN3=		SVN::Notify::Filter::EmailFlatFileDB.3

.include <bsd.port.mk>
