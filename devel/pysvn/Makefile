PORTNAME=	pysvn
PORTVERSION=	1.9.12
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://pysvn.barrys-emacs.org/source_kits/

MAINTAINER=	bra@fsn.hu
COMMENT=	Python binding for Subversion
WWW=		http://pysvn.tigris.org/

LICENSE=	APACHE11
LICENSE_FILE=	${WRKSRC}/../LICENSE.txt

BROKEN=		Fails to build, error: implicit instantiation of undefined template 'std::char_traits<unsigned int>'
EXPIRATION_DATE=2025-10-31

.if ${WITH_SUBVERSION_VER:U} == LTS
LIB_DEPENDS=	libsvn_client-1.so:devel/subversion-lts
.else
LIB_DEPENDS=	libsvn_client-1.so:devel/subversion
.endif
LIB_DEPENDS+=	libneon.so:www/neon \
		libexpat.so:textproc/expat2

USES=		python
USE_PYTHON=	distutils noegginfo concurrent optsuffix
PYDISTUTILS_CONFIGURE_TARGET=	configure
PYDISTUTILS_CONFIGUREARGS=	--apr-inc-dir=${LOCALBASE}/include/apr-1 \
				--svn-inc-dir=${LOCALBASE}/include/subversion-1 \
				--pycxx-dir=${WRKSRC}/../Import/pycxx-7.1.4 \
				--pycxx-src-dir=${WRKSRC}/../Import/pycxx-7.1.4/Src

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
