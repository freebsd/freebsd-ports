# ex:ts=8
# Ports collection Makefile for:	poker-engine
# Date created:			Dec 14, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	poker-engine
PORTVERSION=	1.3.5
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://download.gna.org/pokersource/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A python library that implements poker rules

BUILD_DEPENDS=	${LOCALBASE}/bin/rsync:${PORTSDIR}/net/rsync \
		${PYTHON_SITELIBDIR}/pokereval.py:${PORTSDIR}/games/py-poker-eval \
		${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2 \
		${PYTHON_SITELIBDIR}/libxslt.py:${PORTSDIR}/textproc/py-libxslt
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GNOME=	pkgconfig
USE_PYTHON=	2.5-2.6
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN8=	pokerconfigupgrade.8

post-patch:
	@${REINPLACE_CMD} -e \
		's|{datadir}/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in

test:
	@cd ${WRKSRC} && ${GMAKE} check

.include <bsd.port.mk>
