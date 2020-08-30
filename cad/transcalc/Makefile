# Created by: ijliao
# $FreeBSD$

PORTNAME=	transcalc
PORTVERSION=	0.14
PORTREVISION=	13
CATEGORIES=	cad
MASTER_SITES=	http://transcalc.sourceforge.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Analysis and synthesis tool for RF and microwave transmission lines

USES=		gnome pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes

CFLAGS+=		-fcommon

DEPRECATED=	Unmaintained and dead upstream, does not build with -fno-common (llvm 11)
EXPIRATION_DATE=2021-04-01

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g' ${WRKSRC}/configure

.include <bsd.port.mk>
