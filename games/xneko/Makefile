PORTNAME=	xneko
DISTVERSION=	1.0.1
PORTEPOCH=	1
CATEGORIES=	games

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Classic cat-and-mouse
WWW=		https://github.com/masayuki-koba/xneko

LICENSE=	PD

USES=		imake xorg
USE_GITHUB=	yes
GH_ACCOUNT=	masayuki-koba
USE_XORG=	x11 xorgproto

PLIST_FILES=	bin/xneko share/man/man6/xneko.6.gz

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.mk>
