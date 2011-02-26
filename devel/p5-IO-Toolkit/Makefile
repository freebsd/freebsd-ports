# New ports collection makefile for:	p5-IO-Toolkit
# Date created:		2006-07-12
# Whom:			Yuan-Chung Hsiao <ychsiao@ychsiao.org>
#
# $FreeBSD$
#

PORTNAME=	IO-Toolkit
PORTVERSION=	1.008
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	http://backpan.perl.org/authors/id/L/LI/LINMAR/${PORTNAME:S/-//}/
PKGNAMEPREFIX=	p5-

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	IO::Toolkit - Perl extension to create logfiles

BUILD_DEPENDS=	p5-Crypt-RC6>=0:${PORTSDIR}/security/p5-Crypt-RC6
RUN_DEPENDS=	p5-Crypt-RC6>=0:${PORTSDIR}/security/p5-Crypt-RC6

PERL_CONFIGURE=	5.8.0+

MAN3=	IO::Toolkit.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
RUN_DEPENDS+=	p5-Digest-MD5>=2.16:${PORTSDIR}/security/p5-Digest-MD5
BUILD_DEPENDS+=	p5-Digest-MD5>=2.16:${PORTSDIR}/security/p5-Digest-MD5
.endif

.include <bsd.port.post.mk>
