# New ports collection Makefile for:	xrmftp
# Date created:				28 March 2000
# Whom:					Matt Heckaman <matt@LUCIDA.CA>
#
# $FreeBSD$
#

PORTNAME=	xrmftp
PORTVERSION=	1.2.4
PORTREVISION=	4
CATEGORIES=	ftp
MASTER_SITES=	http://www-users.mat.uni.torun.pl/~rafmet/xrmftp/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical FTP client based on the xforms library

LIB_DEPENDS=	forms.1:${PORTSDIR}/x11-toolkits/xforms

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.src

ALL_TARGET=	xrmftp
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/X11
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" \
		LDFLAGS="-L/usr/lib -L${LOCALBASE}/lib -lm -lX11 -lforms -lXpm"

PORTDOCS=	CHANGES FIXED-BUGS README
PLIST_FILES=	bin/xrmftp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xrmftp ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in CHANGES FIXED-BUGS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
