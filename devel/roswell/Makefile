PORTNAME=	roswell
DISTVERSIONPREFIX=	v
DISTVERSION=	24.10.115
CATEGORIES=	devel lisp

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Common Lisp installer and launcher
WWW=		https://roswell.github.io/

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/bin/curl:ftp/curl
RUN_DEPENDS=	${LOCALBASE}/bin/automake:devel/automake \
		${LOCALBASE}/bin/curl:ftp/curl

USES=		autoreconf localbase uidfix
USE_GITHUB=	yes

GNU_CONFIGURE=	yes

pre-configure:
	(cd ${WRKSRC}/ && ${SH} bootstrap)

.include <bsd.port.mk>
