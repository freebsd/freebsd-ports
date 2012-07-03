# ports collection makefile for:	feh
# Date created:				16 Oct 2000
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	feh
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://feh.finalrewind.org/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	uqs

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	An image viewer that utilizes Imlib2

LICENSE=	MIT

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		giblib.1:${PORTSDIR}/graphics/giblib

USE_XORG=	x11 xt xinerama
USE_PERL5_RUN=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes

MAN1=		feh.1 feh-cam.1 gen-cam-menu.1

CPPFLAGS+=	-I${LOCALBASE}/include -std=c99
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"

PORTDOCS=	AUTHORS ChangeLog README TODO

post-patch:
	@${REINPLACE_CMD} 's#/bin/bash#/bin/sh#' ${WRKSRC}/cam/gen-cam-menu
	@${REINPLACE_CMD} 's#/install-man install-doc#install-man#' ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
