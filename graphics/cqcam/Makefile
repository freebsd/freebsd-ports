# New ports collection makefile for:	cqcam
# Date created:		29 Oct 1997
# Whom:			Kensaku Masuda <greg@greg.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	cqcam
PORTVERSION=	0.90p9
CATEGORIES=	graphics
MASTER_SITES=	http://www.cs.duke.edu/~reynolds/cqcam/
DISTNAME=	${PORTNAME}-0.90pre9
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		jpeg.9:${PORTSDIR}/graphics/jpeg

ONLY_FOR_ARCHS=	i386

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -pedantic" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-asm
INSTALL_TARGET=	bininstall

MAN1=		cqcam.1
MLINKS=		cqcam.1 webcam.1 \
		cqcam.1 xcqcam.1

CQCAM_DOCS=	README docs/APINOTES docs/CHANGES docs/README.webcam \
		docs/refresh.html docs/webcam.html

post-install:
.for file in cqcam gtkcam webcam xcqcam
	@strip ${PREFIX}/bin/${file}
.endfor
	${INSTALL_MAN} ${WRKSRC}/docs/cqcam.1 ${PREFIX}/man/man1
	@${MKDIR} ${PREFIX}/share/examples/cqcam
	${INSTALL_DATA} ${WRKSRC}/.cqcrc ${PREFIX}/share/examples/cqcam/sample.cqcrc
	${INSTALL_DATA} ${WRKSRC}/webcam/nph-webcam ${PREFIX}/share/examples/cqcam/sample.nph-webcam
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/cqcam
.for file in ${CQCAM_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/cqcam
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
