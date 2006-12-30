# New ports collection makefile for:	autoconvert
# Date created:		26 Oct 1999
# Whom:			Yin-Jieh Chen <yinjieh@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	autoconvert
PORTVERSION=	0.3.16
CATEGORIES=	chinese
MASTER_SITES=	http://people.debian.org/~ygh/

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	Intelligent Chinese encoding converter

MAKE_ENV=	CFLAG="${CPPFLAGS}" LIBS="${LDFLAGS}"
USE_GETOPT_LONG=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|^CFLAGS|#CFLAGS|" \
		${WRKSRC}/contrib/xchat-plugins/Makefile

pre-install:
	@${MKDIR} ${DATADIR}
.for i in ChangeLog LICENSE Readme TODO Thanks Version
	@${INSTALL_DATA} ${WRKSRC}/$i ${DATADIR}
.endfor

.include <bsd.port.mk>
