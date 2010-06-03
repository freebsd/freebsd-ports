# New ports collection makefile for:	devel/p5-File-HomeDir
# Date created:				3 March 2005
# Whom:					Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	File-HomeDir
PORTVERSION=	0.91
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	Get home directory for self or other users

RUN_DEPENDS=	p5-File-Which>=0:${PORTSDIR}/sysutils/p5-File-Which
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		File::HomeDir.3 \
		File::HomeDir::Darwin.3 \
		File::HomeDir::Darwin::Carbon.3 \
		File::HomeDir::Darwin::Cocoa.3 \
		File::HomeDir::FreeDesktop.3 \
		File::HomeDir::Test.3 \
		File::HomeDir::Unix.3 \
		File::HomeDir::Windows.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500808
RUN_DEPENDS+=	p5-PathTools>=3.12:${PORTSDIR}/devel/p5-PathTools
.endif

.if ${PERL_LEVEL} < 500809
RUN_DEPENDS+=	p5-File-Temp>=0.19:${PORTSDIR}/devel/p5-File-Temp
.endif

.include <bsd.port.post.mk>
