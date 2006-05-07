# New ports collection makefile for:	qemacs
# Date created:				27 January 2003
# Whom:			Brad Davis <so14k@so14k.com> et al
#
# $FreeBSD$
#

PORTNAME=	qemacs
PORTVERSION=	0.3.p.12
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://fabrice.bellard.free.fr/qemacs/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p./pre/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	QEmacs (for Quick Emacs) is a very small but powerful UNIX editor

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_GMAKE=	yes
USE_XLIB=	yes
MAKE_ARGS+=	CFLAGS="${CFLAGS} -I${X11BASE}/include -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
MAN1=		qe.1

post-patch:
	${REINPLACE_CMD} -e 's,HOST_CC,CC,g' ${WRKSRC}/Makefile

do-install:
	cd ${WRKSRC}; ${INSTALL_PROGRAM} qe html2png ${PREFIX}/bin
	${MKDIR} ${DATADIR:S/qemacs/qe/}
	cd ${WRKSRC}; ${INSTALL_DATA} kmaps ligatures ${DATADIR:S/qemacs/qe/}
	${INSTALL_MAN} ${WRKSRC}/qe.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
