# New ports collection makefile for:	SWF-Builder
# Date created:	   25 December 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	SWF-Builder
PORTVERSION=	0.09
CATEGORIES=	graphics www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/Y/YS/YSAS
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Create SWF movie

BUILD_DEPENDS=	${SITE_PERL}/SWF/Element.pm:${PORTSDIR}/graphics/p5-SWF-File \
		${SITE_PERL}/Math/Bezier/Convert.pm:${PORTSDIR}/math/p5-Math-Bezier-Convert \
		${SITE_PERL}/Font/TTF/Font.pm:${PORTSDIR}/x11-fonts/p5-Font-TTF
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		SWF::Builder.3 SWF::Builder::ActionScript.3 \
		SWF::Builder::Character::Bitmap.3 \
		SWF::Builder::Character::EditText.3 \
		SWF::Builder::Character::Font.3 \
		SWF::Builder::Character::MovieClip.3 \
		SWF::Builder::Character::Shape.3 \
		SWF::Builder::Character::Sound.3 \
		SWF::Builder::Character::Text.3 SWF::Builder::Gradient.3
MAN1=		asc.plx.1

post-patch:
	@${FIND} ${WRKSRC} -type f |\
		${XARGS} ${PERL} -pi -e 's/\x0d(?=\x0a)//'

post-configure:
	@${PERL} -pi -e 's/^(POD2MAN_EXE.*)$$/\1 --lax/;' ${WRKSRC}/Makefile

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		Port requires perl 5.8.x or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
