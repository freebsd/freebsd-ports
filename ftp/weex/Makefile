# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	weex
PORTVERSION=	2.8.2
CATEGORIES=	ftp
MASTER_SITES=	SF/weex/weex
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Non-interactive FTP client

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/COPYING

USES=		autoreconf gmake ssl gettext-tools
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

# NLS support is very broken in this release
CONFIGURE_ARGS=	--disable-nls

post-patch:
	@${REINPLACE_CMD} -e 's|^\(SUBDIRS.*\)debian|\1|' \
		${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/sample.weexrc ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
