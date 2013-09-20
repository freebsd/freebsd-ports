# Created by: Hye-Shik Chang <perky@python.or.kr>
# $FreeBSD$

PORTNAME=	paint
PORTVERSION=	0.3
PORTREVISION=	3
CATEGORIES=	graphics python
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/py${PORTNAME}%20${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pypaint-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple and flexible painting adaptor to libart for Python

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		ttf:${PORTSDIR}/print/freetype

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_GNOME=	libartlgpl2
NO_WRKSUBDIR=	yes
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libart-2.0 \
		-I${LOCALBASE}/include/freetype1
LDFLAGS+=	-L${LOCALBASE}/lib

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

NO_STAGE=	yes
.include <bsd.port.options.mk>
post-patch:
	@${REINPLACE_CMD} -e "s,art_lgpl,art_lgpl_2," ${WRKSRC}/setup.py

.if ${PORT_OPTIONS:MEXAMPLES}
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${CP} ${WRKSRC}/test* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
