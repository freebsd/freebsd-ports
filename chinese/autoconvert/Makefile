# New ports collection makefile for:	autoconvert
# Date created:		26 Oct 1999
# Whom:			Yin-Jieh Chen <yinjieh@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	autoconvert
PORTVERSION=	0.3.13
CATEGORIES=	chinese
MASTER_SITES=	http://people.debian.org/~ygh/

MAINTAINER=	yinjieh@csie.nctu.edu.tw

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

INSTALLS_SHLIB=	yes

pre-install:
	@${MKDIR} ${PREFIX}/share/zh-autoconvert
.for i in ChangeLog LICENSE Readme TODO Thanks Version hz.txt procmailrc.example shed.big5 shed.gb shed.uni shed.utf7 shed.utf8
	@${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/zh-autoconvert
.endfor

.include <bsd.port.mk>
