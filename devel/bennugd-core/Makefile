PORTNAME=	core
PORTVERSION=	svn20130912
PORTREVISION=	1
CATEGORIES=	devel games
MASTER_SITES=	https://mirror.amdmi3.ru/distfiles/
PKGNAMEPREFIX=	bennugd-
DISTNAME=	bennugd-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	High level open source game development suite, core libs
WWW=		https://www.bennugd.org/

USES=		dos2unix libtool pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--bindir="${PREFIX}/libexec"
SUB_FILES=	bgdc bgdi
USE_LDCONFIG=	yes
DOS2UNIX_GLOB=	*.c *.h
INSTALL_TARGET=	install-strip

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	dies with segmentation fault on !i386

WRKSRC=		${WRKDIR}/bennugd/${PORTNAME}

PLIST_FILES=	bin/bgdc bin/bgdi \
		libexec/bgdc libexec/bgdi \
		lib/libbgdrtm.so

post-extract:
	@${CHMOD} a+x ${WRKSRC}/configure ${WRKSRC}/install-sh

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/configure

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/bgdi ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/bgdc ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
