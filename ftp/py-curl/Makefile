# New ports collection makefile for:	py-curl
# Date created:				2 July 2001
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	curl
PORTVERSION=	7.13.1
CATEGORIES=	ftp python
MASTER_SITES=	http://pycurl.sourceforge.net/download/ \
		http://pycurl.sourceforge.net/download/00-OLD-VERSIONS/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python interface to libcurl

LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_REINPLACE=	yes
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - 2>/dev/null || true

post-patch:
	${REINPLACE_CMD} -e 's@\(curl-config --\)@${LOCALBASE}/bin/\1@g' \
		-e 's@^\(include_dirs = \).*@\1["${LOCALBASE}/include"]@' \
		-e 's@^\(PACKAGE = \).*@\1"py-curl"@' \
		-e 's@\(os.path.join(\)datadir, "examples")@\1"share/examples/py-curl")@' \
		-e 's@name=PACKAGE@name="pycurl"@' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
