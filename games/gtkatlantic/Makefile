# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtkatlantic
PORTVERSION=	0.4.3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://download.tuxfamily.org/gtkatlantic/downloads/v0.4/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A game like Monopoly(tm)

USES=		gmake pkgconfig
USE_BZIP2=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e '/-Werror/s|^|#|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|mkdir |$$(mkdir_p) |g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
