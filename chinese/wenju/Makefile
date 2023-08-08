PORTNAME=	wenju
PORTVERSION=	1.6
PORTREVISION=	4
CATEGORIES=	chinese
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of writing tools in Chinese
WWW=		https://sourceforge.net/projects/wenju/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome libtool pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	reed talkfilters # bin/wrap

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
