# Created by: Gerrit Beine (<gerrit.beine@gmx.de>)
# $FreeBSD$

PORTNAME=	Image_GraphViz
PORTVERSION=	1.3.0
CATEGORIES=	graphics www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	An interface to AT&T's GraphViz tools

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		${LOCALBASE}/bin/dot:${PORTSDIR}/graphics/graphviz

PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
