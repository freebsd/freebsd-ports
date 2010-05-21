# ports collection makefile for:	feh
# Date created:				16 Oct 2000
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	feh
PORTVERSION=	1.5
CATEGORIES=	graphics
MASTER_SITES=	http://www.chaosdorf.de/~derf/feh/ \
		http://people.freebsd.org/~uqs/distfiles/

MAINTAINER=	uqs@FreeBSD.org
COMMENT=	An image viewer that utilizes Imlib2

LIB_DEPENDS=	giblib.1:${PORTSDIR}/graphics/giblib

USE_XORG=	x11 xt xinerama
USE_PERL5_RUN=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes

MAN1=		feh.1 feh-cam.1

CFLAGS=		-I${LOCALBASE}/include -std=c99
LDFLAGS=	-L${LOCALBASE}/lib
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"

post-patch:
	@${REINPLACE_CMD} 's#share/man#man#' ${WRKSRC}/config.mk
	@${REINPLACE_CMD} 's#install-man install-doc install-bin##' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's#/bin/bash#/bin/sh#' ${WRKSRC}/cam/gen-cam-menu

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/feh ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/feh.1 ${PREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/cam/feh-cam ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/cam/gen-cam-menu ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/feh-cam.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
