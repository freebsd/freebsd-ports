# New ports collection makefile for:	py-curl
# Date created:				2 July 2001
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	curl
PORTVERSION=	7.9.8.4
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

post-patch:
	${REINPLACE_CMD} -e 's@\(curl-config --\)@${LOCALBASE}/bin/\1@g' \
		-e 's@os.path.join("doc", "pycurl")@"share/doc/py-curl"@g' \
		-e 's@os.path.join("d.*"examples")@"share/examples/py-curl"@g' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
