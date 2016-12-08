# Created by: Yuan-Chen Cheng <ycheng@sinica.edu.tw>
# $FreeBSD$

PORTNAME=	popt
PORTVERSION=	1.16
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://rpm5.org/files/popt/

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	Getopt(3) like library with a number of enhancements, from Redhat

OPTIONS_DEFINE=	NLS

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
USES=		iconv libtool pathfix
USE_LDCONFIG=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext
OPTIONS_SUB=	yes

.include <bsd.port.mk>
