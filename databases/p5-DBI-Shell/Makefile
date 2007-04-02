# New ports collection makefile for:	p5-DBI-Shell
# Date created:		Sun Jan 18 07:27:41 CST 2004
# Whom:					dcf@aracnet.com
#
# $FreeBSD$
#

PORTNAME=	DBI-Shell
PORTVERSION=	11.93
PORTREVISION=	3
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBI
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive command shell for the DBI

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${BUILD_DEPENDS}
RUN_DEPENDS+=	${SITE_PERL}/Text/Reform.pm:${PORTSDIR}/textproc/p5-Text-Reform \
		${SITE_PERL}/IO/Tee.pm:${PORTSDIR}/devel/p5-IO-Tee

PERL_CONFIGURE=	yes

MAN1=		dbish.1
MAN3=		DBI::Format.3 DBI::Format::SQLMinus.3 DBI::Shell.3

.include <bsd.port.mk>
