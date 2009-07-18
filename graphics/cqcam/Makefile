# New ports collection makefile for:	cqcam
# Date created:		29 Oct 1997
# Whom:			Kensaku Masuda <greg@greg.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	cqcam
PORTVERSION=	0.91
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://www.cs.duke.edu/~reynolds/cqcam/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Color Quickcam control program

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg

ONLY_FOR_ARCHS=	i386

USE_XORG=	x11
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALL_TARGET=	bininstall

MAN1=		cqcam.1
MLINKS=		cqcam.1 webcam.1 \
		cqcam.1 xcqcam.1

MYPORTDOCS=	README docs/APINOTES docs/CHANGES docs/README.webcam \
		docs/refresh.html docs/webcam.html docs/README.movies

post-install:
.for file in cqcam gtkcam webcam xcqcam
	@${STRIP_CMD} ${PREFIX}/bin/${file}
.endfor
	${INSTALL_MAN} ${WRKSRC}/docs/cqcam.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${PREFIX}/share/examples/cqcam
	${INSTALL_DATA} ${WRKSRC}/.cqcrc ${PREFIX}/share/examples/cqcam/sample.cqcrc
	${INSTALL_DATA} ${WRKSRC}/webcam/nph-webcam ${PREFIX}/share/examples/cqcam/sample.nph-webcam
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${MYPORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${SED} -e "s:/usr/local:${PREFIX}:" ${PKGMESSAGE}

.include <bsd.port.mk>
