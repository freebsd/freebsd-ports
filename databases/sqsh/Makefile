PORTNAME=	sqsh
PORTVERSION=	2.5.16.1
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION:R:R}

PATCH_SITES=	https://raw.githubusercontent.com/netzbasis/openbsd-ports/11f6e510cbdf022a7b6c71ee125a41ba443fe927/databases/sqsh/patches/
PATCHFILES=	patch-src_cmd_connect_c

MAINTAINER=	fuz@fuz.su
COMMENT=	Interactive tool for querying Sybase database servers

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libct.so:databases/freetds

USES=		readline tar:tgz
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SYBASE="${LOCALBASE}"
CONFIGURE_ARGS=	--with-readline
ALL_TARGET=	build
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R:R}

PLIST_FILES=	bin/sqsh etc/sqshrc.default man/man1/sqsh.1.gz

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11

X11_USES=	motif
X11_USE=	xorg=x11,xext,xmu,xt
X11_CONFIGURE_ON=	--with-motif --with-x

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/doc/global.sqshrc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/sqsh ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/sqsh.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/doc/global.sqshrc ${STAGEDIR}${PREFIX}/etc/sqshrc.default

.include <bsd.port.mk>
