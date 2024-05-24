PORTNAME=	star_traders
DISTVERSION=	7.20
CATEGORIES=	games
MASTER_SITES=	https://ftp.zap.org.au/pub/trader/unix/
DISTNAME=	trader-${DISTVERSION}

MAINTAINER=	petteri.valkonen@iki.fi
COMMENT=	Simple text-based game of interstellar trading
WWW=		https://www.zap.org.au/projects/trader

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		iconv ncurses tar:xz
GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

WRKSRC=		${WRKDIR}/${DISTNAME}

OPTIONS_DEFINE=		NLS
OPTIONS_DEFAULT=	NLS
OPTIONS_SUB=		yes
NLS_USES=		gettext-runtime
NLS_CONFIGURE_OFF=	--disable-nls

.include <bsd.port.mk>
