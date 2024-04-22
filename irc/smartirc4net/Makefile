PORTNAME=	smartirc4net
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	irc
MASTER_SITES=	https://smuxi.im/jaws/data/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-layered IRC library
WWW=		https://www.meebey.net/projects/smartirc4net/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_MCS=${LOCALBASE}/bin/mcs
USES=		gmake mono pathfix pkgconfig

.include <bsd.port.mk>
