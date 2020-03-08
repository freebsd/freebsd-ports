# Created by: bra@fsn.hu
# $FreeBSD$

PORTNAME=	pysvn
PORTVERSION=	1.9.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://pysvn.barrys-emacs.org/source_kits/

MAINTAINER=	bra@fsn.hu
COMMENT=	Python binding for Subversion

LICENSE=	APACHE11
LICENSE_FILE=	${WRKSRC}/../LICENSE.txt

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

LIB_DEPENDS=	libsvn_client-1.so:devel/subversion \
		libneon.so:www/neon \
		libexpat.so:textproc/expat2

# Python3 ready
USES=		python:-3.6
USE_PYTHON=	distutils noegginfo concurrent optsuffix
PYDISTUTILS_CONFIGURE_TARGET=	configure
PYDISTUTILS_CONFIGUREARGS=	--apr-inc-dir=${LOCALBASE}/include/apr-1 \
				--svn-inc-dir=${LOCALBASE}/include/subversion-1 \
				--pycxx-dir=${WRKSRC}/../Import/pycxx-6.2.8 \
				--pycxx-src-dir=${WRKSRC}/../Import/pycxx-6.2.8/Src

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/${PORTNAME}/__init__.py \
		%%PYTHON_SITELIBDIR%%/${PORTNAME}/_pysvn_${PYTHON_VERSION:S/./_/:S/python//}.so

WRKSRC_SUBDIR=	Source

post-patch:
	${REINPLACE_CMD} -e 's|^min_pycxx_version =|pycxx_version = &|g; s|gcc|${CC}|g; s|g++|${CXX}|g'  ${WRKSRC}/setup_configure.py

do-build:
	@cd ${WRKSRC} && ${MAKE_CMD}

do-install:
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}
	${INSTALL_SCRIPT} \
		${WRKSRC}/${PORTNAME}/*.py \
		${WRKSRC}/${PORTNAME}/*.so \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/*.so

.include <bsd.port.mk>
