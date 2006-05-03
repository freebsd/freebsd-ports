# New ports collection makefile for:	autoconvert
# Date created:		26 Oct 1999
# Whom:			Yin-Jieh Chen <yinjieh@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	autoconvert
PORTVERSION=	0.3.13
CATEGORIES=	chinese
MASTER_SITES=	ftp://banyan.dlut.edu.cn/pub/PEOPLE/saka/

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	Intelligent Chinese encoding converter

USE_GETOPT_LONG=	yes
MAKE_ENV=	CFLAG="${CPPFLAGS}" LIBS="${LDFLAGS}"
INSTALLS_SHLIB=	yes
DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX}${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e "s|^CFLAGS|#CFLAGS|" \
		${WRKSRC}/contrib/xchat-plugins/Makefile

pre-install:
	@${MKDIR} ${DATADIR}
.for i in ChangeLog LICENSE Readme TODO Thanks Version hz.txt procmailrc.example shed.big5 shed.gb shed.uni shed.utf7 shed.utf8
	@${INSTALL_DATA} ${WRKSRC}/$i ${DATADIR}
.endfor

.include <bsd.port.mk>
