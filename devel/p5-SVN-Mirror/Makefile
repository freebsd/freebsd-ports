# New ports collection makefile for:	devel/p5-SVN-Mirror
# Date created:				Mar 15 2004
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	SVN-Mirror
PORTVERSION=	0.41
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/C/CL/CLKAO
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@infor.org
COMMENT=	Mirror remote subversion repository to local

BUILD_DEPENDS=	${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/${PERL_ARCH}/Data/UUID.pm:${PORTSDIR}/devel/p5-Data-UUID \
    		${SITE_PERL}/VCP.pm:${PORTSDIR}/devel/p5-VCP \
    		${SITE_PERL}/SVN/Simple/Edit.pm:${PORTSDIR}/devel/p5-SVN-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

CONFIGURE_ENV=	PERL_EXTUTILS_AUTOINSTALL=--skipdeps
PERL_CONFIGURE=	yes

MAN1=		svm.1
MAN3=		SVN::Mirror.3

.include <bsd.port.mk>
