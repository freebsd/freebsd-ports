# New ports collection makefile for:	py-curl
# Date created:				2 July 2001
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	curl
PORTVERSION=	0.4.5
CATEGORIES=	ftp python
MASTER_SITES=	http://pycurl.sourceforge.net/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	perky@fallin.lv

BUILD_DEPENDS=	${PYDISTUTILS}
LIB_DEPENDS=	curl.2:${PORTSDIR}/ftp/curl

USE_PYTHON=	yes
PLIST_SUB+=	PYTHON_SITELIBDIR="lib/${PYTHON_VERSION}/site-packages"
PYDIST_SETUP=	cd ${WRKSRC} && ${PYTHON_CMD} setup.py

post-patch:
.for file in ${REPATCHFILES}
	${PERL} -pi -e 's@"include"@"${LOCALBASE}/include"],library_dirs=["${LOCALBASE}/lib"@' \
		${WRKSRC}/setup.py
.endfor

do-build:
	${PYDIST_SETUP} build

do-install:
	${PYDIST_SETUP} install -c -O1 --prefix=${PREFIX}
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/py-curl
	cd ${WRKSRC} && ${INSTALL_DATA} tests/* ${PREFIX}/share/examples/py-curl
.endif

.include <bsd.port.mk>
