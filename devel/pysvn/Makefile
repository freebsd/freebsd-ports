# Created by: bra@fsn.hu
# $FreeBSD$

PORTNAME=	pysvn
PORTVERSION=	1.7.8
CATEGORIES=	devel
MASTER_SITES=	http://pysvn.barrys-emacs.org/source_kits/

MAINTAINER=	bra@fsn.hu
COMMENT=	Python binding for Subversion

LICENSE=	APACHE20

LIB_DEPENDS=	svn_client-1:${PORTSDIR}/devel/subversion \
		neon:${PORTSDIR}/www/neon29

# Python3 ready
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_NOEGGINFO=	yes
PYDISTUTILS_CONFIGURE_TARGET=	configure
PYDISTUTILS_CONFIGUREARGS=	--apr-inc-dir=${LOCALBASE}/include/apr-1 \
				--svn-root-dir=${LOCALBASE}

PLIST_SUB=	PYTHONVER=${PYTHON_VERSION:S/./_/:S/python//}
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/${PORTNAME}/__init__.py \
		%%PYTHON_SITELIBDIR%%/${PORTNAME}/_pysvn_%%PYTHONVER%%.so
PLIST_DIRS=	%%PYTHON_SITELIBDIR%%/${PORTNAME}

WRKSRC=		${WRKDIR}/${DISTNAME}/Source

NO_STAGE=	yes

post-patch:
	${REINPLACE_CMD} -e "s,gcc,${CC},g" -e "s,g++,${CXX},g" ${WRKSRC}/setup_configure.py

do-build:
	@cd ${WRKSRC} && ${MAKE}

pre-install:
	${MKDIR} ${PYTHONPREFIX_SITELIBDIR}
	${MKDIR} ${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} \
		${WRKSRC}/${PORTNAME}/*.py \
		${WRKSRC}/${PORTNAME}/*.so \
		${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}

.include <bsd.port.mk>
