# New ports collection makefile for:	taglib
# Date Created:				06 Nov 2003
# Whom:				 	Frank Laszlo <laszlof@vonostingroup.com>
#
# $FreeBSD$
#

PORTNAME=	taglib
PORTVERSION=	1.5
CATEGORIES=	audio
MASTER_SITES=	http://ktown.kde.org/~wheeler/files/src/

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	Library for manipulating ID3 tags and Ogg comments

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e \
	"s#\$$(libdir)/pkgconfig#${PREFIX}/libdata/pkgconfig#g" \
	${WRKSRC}/Makefile.in ${WRKSRC}/bindings/c/Makefile.in

.include <bsd.port.mk>
