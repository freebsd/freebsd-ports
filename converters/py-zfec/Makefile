# Created by: Kevin Lo <kevlo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zfec
PORTVERSION=	1.4.22
PORTREVISION=	1
CATEGORIES=	converters python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	A fast erasure codec

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.GPL

BUILD_DEPENDS=	darcsver:${PORTSDIR}/devel/py-darcsver \
		unsort:${PORTSDIR}/devel/py-pyutil
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_NOEGGINFO=  yes
PYEASYINSTALL_ARCHDEP=  yes

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|share/doc|${DOCSDIR}|g ; \
		s#(doc_loc, data_fnames)##g' ${WRKSRC}/setup.py

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for DOC in COPYING.GPL COPYING.TGPPL.html README.rst TODO changelog
	${INSTALL_DATA} ${WRKSRC}/${DOC} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
