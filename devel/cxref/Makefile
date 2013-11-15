# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cxref
PORTVERSION=	1.6d
CATEGORIES=	devel
MASTER_SITES=	http://www.gedanken.demon.co.uk/download-cxref/ \
		http://fossies.org/linux/misc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C program cross-referencing & documentation tool

LICENSE=	GPLv2

USES=		gmake shebangfix
SHEBANG_FILES=	contrib/xrgr.pl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-cxref-cpp
ALL_TARGET=	programs

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/*.pl ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/*.el ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/README* ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
