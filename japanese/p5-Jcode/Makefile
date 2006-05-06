# New ports collection makefile for:	Jcode
# Date created:		7 Nov 1999
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Jcode
PORTVERSION=	2.04
CATEGORIES=	japanese perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/D/DA/DANKOGAI

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension interface to convert Japanese text

PERL_CONFIGURE=	yes
MAN3=		Jcode.3 Jcode::Nihongo.3

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

.if ${PERL_LEVEL} < 500801
BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64
MAN3+=		Jcode::Unicode.3 Jcode::Unicode::Constants.3 \
		Jcode::Unicode::NoXS.3
PLIST_SUB=	WRAPPER="@comment " REALMOD=""
.else
PLIST_SUB=	WRAPPER="" REALMOD="@comment "
.endif

.include <bsd.port.post.mk>
