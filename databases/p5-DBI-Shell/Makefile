# New ports collection makefile for:	p5-DBI-Shell
# Date created:		Sun Jan 18 07:27:41 CST 2004
# Whom:					dcf@aracnet.com
#
# $FreeBSD$
#

PORTNAME=	DBI-Shell
PORTVERSION=	11.93
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBI
PKGNAMEPREFIX=	p5-

MAINTAINER=	dcf@aracnet.com
COMMENT=	Interactive command shell for the DBI

PERL_CONFIGURE=	yes

MAN1=		dbish.1
MAN3=		DBI::Format.3 DBI::Format::SQLMinus.3 DBI::Shell.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
.endif
RUN_DEPENDS+=	${SITE_PERL}/Text/Reform.pm:${PORTSDIR}/textproc/p5-Text-Reform
RUN_DEPENDS+=	${SITE_PERL}/IO/Tee.pm:${PORTSDIR}/devel/p5-IO-Tee

.include <bsd.port.post.mk>
