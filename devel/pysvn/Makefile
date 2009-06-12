# New ports collection makefile for:	pysvn
# Date created:        22 April 2008
# Whom:                bra@fsn.hu
#
# $FreeBSD$
#

PORTNAME=	pysvn
PORTVERSION=	1.7.0
CATEGORIES=	devel
MASTER_SITES=	http://pysvn.barrys-emacs.org/source_kits/

MAINTAINER=	bra@fsn.hu
COMMENT=	Python binding for Subversion

LIB_DEPENDS=	svn_client-1:${PORTSDIR}/devel/subversion \
		neon.28:${PORTSDIR}/www/neon28

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_NOEGGINFO=yes
PYDISTUTILS_CONFIGURE_TARGET=configure
PYDISTUTILS_CONFIGUREARGS=--apr-inc-dir=${LOCALBASE}/include/apr-1 \
			  --svn-root-dir=${LOCALBASE}

PYVERSION=	${PYTHON_VERSION:S/^python//}

PLIST_SUB=	PYTHONVER=${PYTHON_VERSION:S/./_/:S/python//}
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/${PORTNAME}/__init__.py \
		%%PYTHON_SITELIBDIR%%/${PORTNAME}/_pysvn_%%PYTHONVER%%.so
PLIST_DIRS=	%%PYTHON_SITELIBDIR%%/${PORTNAME}

WRKSRC=		${WRKDIR}/${DISTNAME}/Source

.include <bsd.port.pre.mk>
.if defined(PYTHON_VERSION) && ${PYVERSION:S/.//} < 26
pre-configure:
	@cd ${WRKSRC} && ${PYTHON_CMD} setup.py backport
.endif

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

.include <bsd.port.post.mk>
