# ports collection makefile for:	feh
# Date created:				16 Oct 2000
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	feh
PORTVERSION=	2.0
CATEGORIES=	graphics
MASTER_SITES=	http://feh.finalrewind.org/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	uqs

MAINTAINER=	uqs@FreeBSD.org
COMMENT=	An image viewer that utilizes Imlib2

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		giblib.1:${PORTSDIR}/graphics/giblib

USE_XORG=	x11 xt xinerama
USE_PERL5_RUN=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes

MAN1=		feh.1 feh-cam.1 gen-cam-menu.1

CFLAGS+=	-I${LOCALBASE}/include -std=c99
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"

post-patch:
	@${REINPLACE_CMD} 's#share/man#man#' ${WRKSRC}/config.mk
	@${REINPLACE_CMD} 's#install-man install-doc install-bin#install-doc#' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's#/bin/bash#/bin/sh#' ${WRKSRC}/cam/gen-cam-menu

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/feh ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/cam/feh-cam ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/cam/gen-cam-menu ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/feh.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/feh-cam.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/gen-cam-menu.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
