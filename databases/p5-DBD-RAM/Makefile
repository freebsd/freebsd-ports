# New ports collection makefile for:    p5-DBD-RAM
# Date created:				Nov 15 2003
# Whom:	      				vanilla
#
# $FreeBSD$
#

PORTNAME=	DBD-RAM
PORTVERSION=	0.072
PORTREVISION=	0
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DBI driver for files and data structures

BUILD_DEPENDS+=	${SITE_PERL}/DBD/File.pm:${PORTSDIR}/databases/p5-DBD-File
RUN_DEPENDS+=	${SITE_PERL}/DBD/File.pm:${PORTSDIR}/databases/p5-DBD-File

PERL_CONFIGURE=	yes

MAN3=		DBD::RAM.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
.endif

.include <bsd.port.post.mk>
