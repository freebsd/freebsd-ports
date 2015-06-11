# Created by: nbm
# $FreeBSD$

PORTNAME=	ithought
PORTVERSION=	a5
PORTREVISION=	8
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-alpha

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensible text management system

USES=		libtool
USE_GNOME=	gtk12 libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/libexec

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/ithought/module_actions/*.so

.include <bsd.port.mk>
