# New ports collection makefile for:	py-curl
# Date created:				2 July 2001
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	curl
PORTVERSION=	0.4.2
CATEGORIES=	ftp python
MASTER_SITES=	http://pycurl.sourceforge.net/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	perky@python.or.kr

BUILD_DEPENDS=	${PYDISTUTILS}
LIB_DEPENDS=	curl.2:${PORTSDIR}/ftp/curl

USE_PYTHON=	yes
PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S,^${LOCALBASE}/,,g} \
		SHARE_SUBDIR=${SHARE_SUBDIR}
SHARE_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}
PYDIST_SETUP=	cd ${WRKSRC} && ${PYTHON_CMD} setup.py

REPATCH=	cd ${WRKSRC} && ${SED}
REPATCHSUBST=	-e 's@"include"@"${LOCALBASE}/include"],library_dirs=["${LOCALBASE}/lib"@'
REPATCHFILES=	setup.py
TMPSUFFIX=	.temp

post-patch:
.for file in ${REPATCHFILES}
	${REPATCH} ${REPATCHSUBST} ${file} > ${file}${TMPSUFFIX} && \
		${CAT} ${file}${TMPSUFFIX} > ${file}
.endfor

do-build:
	${PYDIST_SETUP} build

do-install:
	${PYDIST_SETUP} install
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/${SHARE_SUBDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} tests/* ${PREFIX}/share/examples/${SHARE_SUBDIR}
.endif

.include <bsd.port.mk>
