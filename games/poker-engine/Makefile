# ex:ts=8
# Ports collection Makefile for:	poker-engine
# Date created:			Dec 14, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	poker-engine
PORTVERSION=	1.3.4
PORTREVISION=	0
CATEGORIES=	games
MASTER_SITES=	http://download.gna.org/pokersource/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A python library that implements poker rules

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2 \
		${PYTHON_SITELIBDIR}/libxslt.py:${PORTSDIR}/textproc/py-libxslt \
		${PYTHON_SITELIBDIR}/pokereval.py:${PORTSDIR}/games/py-poker-eval \
		${LOCALBASE}/bin/rsync:${PORTSDIR}/net/rsync
BUILD_DEPENDS=	${RUN_DEPENDS}

USE_GNOME=	pkgconfig
USE_PYTHON=	2.4+
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN8=	pokerconfigupgrade.8

post-patch:
	@${REINPLACE_CMD} -e \
		's|{datadir}/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in

test:
	@cd ${WRKSRC} && ${GMAKE} check

.include <bsd.port.mk>
