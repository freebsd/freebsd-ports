# New ports collection makefile for:	p5-ming
# Date created:		18 September 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ming
PORTVERSION=	0.2a
CATEGORIES=	graphics perl5
MASTER_SITES=	# none
PKGNAMEPREFIX=	p5-
DISTFILES=	# none

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Perl5 module for Ming which allows you to create Flash 4/5 movies

EXTRACT_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/graphics/ming:patch
LIB_DEPENDS=	ming.3:${PORTSDIR}/graphics/ming

USE_PERL5=	yes

MD5_FILE=	${.CURDIR}/../ming/distinfo

WRKSRC=		${WRKDIR}/${DISTNAME}/perl_ext
PERL_CONFIGURE=	yes
CONFIGURE_ENV=	LOCALBASE="${LOCALBASE}"

MAN3=		SWF.3 \
		SWF::Action.3 \
		SWF::Bitmap.3 \
		SWF::Button.3 \
		SWF::DisplayItem.3 \
		SWF::Morph.3 \
		SWF::Shape.3 \
		SWF::Sprite.3

EXAMPLES=	examples/*

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -s `cd ${PORTSDIR}/graphics/ming && ${MAKE} -V WRKDIR`/* ${WRKDIR}/

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/perl5/${PORTNAME}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/examples/perl5/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
