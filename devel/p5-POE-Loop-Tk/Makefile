# New ports collection makefile for:	p5-POE-Loop-Tk
# Date created:		2011-10-10
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	POE-Loop-Tk
PORTVERSION=	1.304
CATEGORIES=	devel tk perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A bridge that allows POE to be driven by Tk

BUILD_DEPENDS=	p5-POE>=1.289:${PORTSDIR}/devel/p5-POE \
		p5-Tk>=804.028:${PORTSDIR}/x11-toolkits/p5-Tk
RUN_DEPENDS=	p5-POE>=1.289:${PORTSDIR}/devel/p5-POE \
		p5-Tk>=804.028:${PORTSDIR}/x11-toolkits/p5-Tk

PERL_CONFIGURE=	yes

MAN3=		POE::Loop::Tk.3 \
		POE::Loop::TkActiveState.3 \
		POE::Loop::TkCommon.3

post-patch:
	@${REINPLACE_CMD} -e '/POE::Test::Loops/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
