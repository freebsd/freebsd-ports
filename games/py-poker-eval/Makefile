# ex:ts=8
# Ports collection Makefile for:	py-poker-eval
# Date created:			Dec 14, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	poker-eval
PORTVERSION=	0.137
CATEGORIES=	games python
MASTER_SITES=	http://download.gna.org/pokersource/sources/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION:E}.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python adaptor for the poker-eval toolkit

LIB_DEPENDS=	poker-eval.1:${PORTSDIR}/games/poker-eval

USE_GNOME=	pkgconfig
USE_PYTHON=	2.3+
GNU_CONFIGURE=	yes

PLIST_SUB=	PYVER=${_PYTHON_VERSION:S/./_/}

do-configure:
	@cd ${CONFIGURE_WRKSRC} && ./${CONFIGURE_SCRIPT}

post-patch:
	@${REINPLACE_CMD} -e \
		's|{libdir}/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in

test:
	@cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.mk>
