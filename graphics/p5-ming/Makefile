# New ports collection makefile for:	p5-ming
# Date created:		18 September 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ming
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-perl-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl5 module for Ming which allows you to create Flash 4/5 movies

LIB_DEPENDS=	ming.4:${PORTSDIR}/graphics/ming

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/perl_ext

PERL_CONFIGURE=	yes
CONFIGURE_ENV=	LOCALBASE="${LOCALBASE}"

MAN3=		SWF.3 \
		SWF::Action.3 \
		SWF::Bitmap.3 \
		SWF::Button.3 \
		SWF::Constants.3 \
		SWF::DisplayItem.3 \
		SWF::Morph.3 \
		SWF::Movie.3 \
		SWF::Shape.3 \
		SWF::Sound.3 \
		SWF::Sprite.3 \
		SWF::TextField.3 \
		SWF::VideoStream.3

post-patch:
	@${ECHO_CMD} -n > ${WRKSRC}/../configure.in
	@${LN} -sf ${LOCALBASE}/include/ming ${WRKSRC}/../src

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
