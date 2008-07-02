# New ports collection makefile for:	devel/p5-CPAN-Mini
# Date created:				16 February 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CPAN-Mini
PORTVERSION=	0.571
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	CPAN::Mini - create a minimal mirror of CPAN

RUN_DEPENDS=	p5-Compress-Zlib>=1.20:${PORTSDIR}/archivers/p5-Compress-Zlib \
		p5-File-HomeDir>=0.57:${PORTSDIR}/devel/p5-File-HomeDir \
		p5-libwww>=5:${PORTSDIR}/www/p5-libwww \
		p5-URI>=1:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	minicpan.1
MAN3=	CPAN::Mini.3 CPAN::Mini::App.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
RUN_DEPENDS+=	p5-Scalar-List-Utils>0:${PORTSDIR}/lang/p5-Scalar-List-Utils
BUILD_DEPENDS+=	p5-Scalar-List-Utils>0:${PORTSDIR}/lang/p5-Scalar-List-Utils
.endif

.include <bsd.port.post.mk>
