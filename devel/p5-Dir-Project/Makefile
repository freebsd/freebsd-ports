# New ports collection makefile for:	p5-Dir-Project
# Date created:		2006-07-15
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Dir-Project
PORTVERSION=	3.015
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Project Environment determination

PERL_CONFIGURE=	yes
CONFIGURE_ENV+=	DIRPROJECT_PREFIX=${PREFIX}

MAN1=		project_bin.1 project_dir.1
MAN3=		Dir::Project.3

.include <bsd.port.mk>
