# Created by: Yuan-Chen Cheng <ycheng@sinica.edu.tw>
# $FreeBSD$

PORTNAME=	popt
PORTVERSION=	1.16
CATEGORIES=	devel
MASTER_SITES=	http://rpm5.org/files/popt/

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	Getopt(3) like library with a number of enhancements, from Redhat

OPTIONS_DEFINE=	NLS

CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG} \
		--program-prefix=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USES=		pathfix iconv
USE_LDCONFIG=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext
OPTIONS_SUB=	yes

.include <bsd.port.mk>
