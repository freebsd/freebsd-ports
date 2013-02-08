# Created by: Thomas Gellekum <tg@freebsd.org>
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

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-cxref-cpp
ALL_TARGET=	programs
MAKE_JOBS_SAFE=	yes

MAN1=		cxref.1 cxref-query.1

post-install:
	@${MKDIR} ${DATADIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/contrib/*.pl ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/contrib/*.el ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/contrib/README* ${DATADIR}

.include <bsd.port.mk>
