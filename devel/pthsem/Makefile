PORTNAME=	pthsem
PORTVERSION=	2.0.8
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://www.auto.tuwien.ac.at/~mkoegler/pth/
DISTFILES=	${PORTNAME}_${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	bkoenig@alpha-tierchen.de
COMMENT=	GNU Portable Threads with semaphores
WWW=		https://www.auto.tuwien.ac.at/~mkoegler/index.php/pth

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USES=		gmake libtool pathfix
INSTALL_TARGET=	install-strip

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
