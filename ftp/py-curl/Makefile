# New ports collection makefile for:	py-curl
# Date created:				2 July 2001
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	curl
PORTVERSION=	7.10.3
CATEGORIES=	ftp python
MASTER_SITES=	http://pycurl.sourceforge.net/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org

LIB_DEPENDS=	curl.2:${PORTSDIR}/ftp/curl

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_REINPLACE=	yes
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - 2>/dev/null || true

.include <bsd.port.pre.mk>
CURL_VERSION!=	${LOCALBASE}/bin/curl-config --version|grep '${PORTVERSION}$$' \
		2>&1 || ${TRUE}
.if empty(CURL_VERSION)
IGNORE=		requires curl-${PORTVERSION}
.endif

post-patch:
	${REINPLACE_CMD} -e 's@\(curl-config --\)@${LOCALBASE}/bin/\1@g' \
		-e 's@^\(include_dirs = \).*@\1["${LOCALBASE}/include"]@' \
		-e 's@^\(PACKAGE = \).*@\1"py-curl"@' \
		-e 's@\(os.path.join(\)datadir, "examples")@\1"share/examples/py-curl")@' \
		-e 's@name=PACKAGE@name="pycurl"@' \
		${WRKSRC}/setup.py

.include <bsd.port.post.mk>
