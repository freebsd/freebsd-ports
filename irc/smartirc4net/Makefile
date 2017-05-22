# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	smartirc4net
PORTVERSION=	1.1
CATEGORIES=	irc
MASTER_SITES=	https://smuxi.im/jaws/data/files/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Multi-layered IRC library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_MCS=${LOCALBASE}/bin/mcs
USES=		gmake mono pathfix pkgconfig

.include <bsd.port.mk>
