# $FreeBSD$

PORTNAME=	roswell
DISTVERSIONPREFIX=	v
DISTVERSION=	20.06.14.107
CATEGORIES=	devel lisp

MAINTAINER=	cda@rootkey.co.uk
COMMENT=	Common Lisp installer and launcher

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/bin/curl:ftp/curl
RUN_DEPENDS=	${LOCALBASE}/bin/automake:devel/automake \
		${LOCALBASE}/bin/curl:ftp/curl

USES=	uidfix autoreconf

LDFLAGS+=	-L${LOCALBASE}/lib/
CFLAGS+=	-I${LOCALBASE}/include/

USE_GITHUB=	yes
GH_ACCOUNT=	roswell

GNU_CONFIGURE=	yes

pre-configure:
	(cd ${WRKSRC}/ && ${SH} bootstrap)

.include <bsd.port.mk>
