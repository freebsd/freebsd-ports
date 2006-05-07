# New ports collection makefile for:	py-paint
# Date created:				8 July 2001
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	paint
PORTVERSION=	0.3
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pypaint
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pypaint-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Simple and flexible painting adaptor to libart for Python

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_FREETYPE=	yes
USE_GNOME=	libartlgpl2
NO_WRKSUBDIR=	yes
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libart-2.0 -I${LOCALBASE}/include/freetype1
MAKE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e "s,art_lgpl,art_lgpl_2," ${WRKSRC}/setup.py

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${CP} ${WRKSRC}/test* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
