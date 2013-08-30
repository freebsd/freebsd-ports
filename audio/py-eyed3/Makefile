# Created by: Hye-Shik Chang <perky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	eyed3
PORTVERSION=	0.6.18
CATEGORIES=	audio python
MASTER_SITES=	http://eyed3.nicfit.net/releases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	eyeD3-${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Python module for processing ID3 tags

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_PYTHON=	2.6-2.7
USE_PYTHON_PREFIX=	yes
USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PYTHON="${PYTHON_CMD}"
MAKE_ENV=	SETUP_ARGS_BUILD="${PYDISTUTILS_BUILDARGS}" \
		SETUP_ARGS_INSTALL="${PYDISTUTILS_INSTALLARGS}"
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

MAN1=		eyeD3.1
MANCOMPRESSED=	yes

INSTALLS_EGGINFO=	yes
PYDISTUTILS_PKGNAME=	eyeD3

post-patch:
	${REINPLACE_CMD} -e 's,PYTHON="",,g' -e 's,/usr/local,${LOCALBASE},g' \
		-e 's,2\\\.\[23456789\]\\\.,2.[23456789],g' \
		${WRKSRC}/configure
	${REINPLACE_CMD} -e 's,\(setup.py build\),\1 $${SETUP_ARGS_BUILD},g' \
		-e 's,\(setup.py install\),\1 $${SETUP_ARGS_INSTALL} ,g' \
		-e 's,^docdir:=.*,docdir:=${DOCSDIR},g' \
		${WRKSRC}/Makefile.in
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's,.*docdir.*,#,g' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
