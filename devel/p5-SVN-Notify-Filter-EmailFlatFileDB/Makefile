# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	SVN-Notify-Filter-EmailFlatFileDB
PORTVERSION=	1.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts account names to email address based on a flat-file database

RUN_DEPENDS=	p5-SVN-Notify>=2.72:${PORTSDIR}/devel/p5-SVN-Notify
BUILD_DEPENDS=	p5-SVN-Notify>=2.72:${PORTSDIR}/devel/p5-SVN-Notify

USES=		perl5
USE_PERL5=	configure

MAN3=		SVN::Notify::Filter::EmailFlatFileDB.3

NO_STAGE=	yes
.include <bsd.port.mk>
