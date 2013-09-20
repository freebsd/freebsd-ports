# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	netradiant
PORTVERSION=	20130630
PORTREVISION=	1
CATEGORIES=	games cad
MASTER_SITES=	http://ingar.satgnu.net/gtkradiant/files/ \
		http://freebsd.nsu.ru/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} q3map2.6
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Fork of the well-known GtkRadiant 1.5 FPS games map editor

LICENSE=	GPLv2

LIB_DEPENDS=	libgtkglext-x11-1.0.so:${PORTSDIR}/x11-toolkits/gtkglext \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libwebp.so:${PORTSDIR}/graphics/webp

USES=		gmake pkgconfig
USE_BZIP2=	yes
USE_GL=		gl
USE_GNOME=	gtk20 libxml2
MAKE_ENV=	BUILD=release DOWNLOAD_GAMEPACKS=no LIBS_DL="" \
		RADIANT_ABOUTMSG="For ${OPSYS} ${OSREL} (${ARCH})"

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES=	${PORTNAME}
SUB_LIST=	ARCH=${ARCH}

MAN6=		q3map2.6

NO_STAGE=	yes
post-patch:
# Add missing checks for __FreeBSD__
	@${FIND} ${WRKSRC}/tools -name '*.[ch]' | ${XARGS} ${REINPLACE_CMD} \
		-e 's/__linux__/__${OPSYS}__ ) || defined ( &/'
# Fix the build against Clang
	@${REINPLACE_CMD} -e '/#include "generic\/reference\.h"/x ; 288G' \
		${WRKSRC}/libs/scenelib.h
	@${REINPLACE_CMD} -e '/#include "generic\/referencecounted\.h/ { \
		x ; s/^/#include "scenelib.h"/ ; G ; }' \
			${WRKSRC}/plugins/mapq3/parse.h

do-install:
# Fix permissions of some files (drop bogus execute bit)
	@${FIND} ${WRKSRC}/install/osirion.game -type f | ${XARGS} ${CHMOD} a-x
	@${CHMOD} a-x ${WRKSRC}/install/games/osirion.game
# Remove extra copy of GNU GPL from what we install
	@${RM} ${WRKSRC}/install/GPL.txt
	@${MKDIR} ${DATADIR}
	${CP} -a ${WRKSRC}/install/* ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${DISTDIR}/${MAN6} ${MANPREFIX}/man/man6

.include <bsd.port.mk>
