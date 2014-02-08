# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cxref
PORTVERSION=	1.6e
CATEGORIES=	devel
MASTER_SITES=	http://www.gedanken.org.uk/software/cxref/download/ \
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
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC}/contrib && ${INSTALL_DATA} *.el *.pl *.py README* \
		${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
