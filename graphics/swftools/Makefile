# ex:ts=8
# Ports collection makefile for:	swftools
# Date created:			Feb 9, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	swftools
PORTVERSION=	0.2.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.quiss.org/swftools/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		t1:${PORTSDIR}/devel/t1lib

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes

MAN1=	jpeg2swf.1 pdf2swf.1 swfcombine.1 swfdump.1 swfextract.1 swfstrings.1

.include <bsd.port.mk>
