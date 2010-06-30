# New ports collection makefile for:	autoconvert
# Date created:		26 Oct 1999
# Whom:			Yin-Jieh Chen <yinjieh@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	autoconvert
PORTVERSION=	0.3.16
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	libhz
DISTFILES=	zh-${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Intelligent Chinese encoding converter

MAKE_ENV=	CFLAG="${CPPFLAGS}" LIBS="${LDFLAGS}"
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|^CFLAGS|#CFLAGS|" \
		${WRKSRC}/contrib/xchat-plugins/Makefile

pre-install:
	@${MKDIR} ${DATADIR}
.for i in ChangeLog LICENSE Readme TODO Thanks Version
	@${INSTALL_DATA} ${WRKSRC}/$i ${DATADIR}
.endfor

.include <bsd.port.mk>
