PORTNAME=	csoap
PORTVERSION=	1.1.0
PORTREVISION=	6
CATEGORIES=	devel net www
MASTER_SITES=	SF/${PORTNAME}/libsoap/${PORTVERSION}
DISTNAME=	libsoap-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Client/server SOAP library written in pure C
WWW=		https://csoap.sourceforge.net/

GNU_CONFIGURE=	yes
USES=		gnome libtool pathfix
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

WRKSRC=		${WRKDIR}/libsoap-${PORTVERSION}

.include <bsd.port.mk>
