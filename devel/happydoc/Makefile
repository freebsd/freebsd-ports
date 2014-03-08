# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	happydoc
PORTVERSION=	3.1
CATEGORIES=	devel python
MASTER_SITES=	SF/${PORTNAME}/HappyDoc/${PORTVERSION}
DISTNAME=	HappyDoc_r${PORTVERSION:S/./_/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for extracting documentation from Python source code

LICENSE=	HPND ZPL21
LICENSE_COMB=	multi
LICENSE_NAME_HPND=	Historical Permission Notice and Disclaimer
LICENSE_FILE_HPND=	${WRKSRC}/LICENSE.txt
LICENSE_GROUPS_HPND=	OSI
LICENSE_PERMS_HPND=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

DEPRECATED=	Unmaintained since 2001
EXPIRATION_DATE=	2014-04-12
WRKSRC=		${WRKDIR}/HappyDoc3-r${PORTVERSION:S/./_/g}

USE_PYTHON=	yes

PLIST=		${WRKDIR}/PLIST

NO_STAGE=	yes
pre-build:
	@${FIND} ${WRKSRC} \( -name  ".*" -or -name "*.orig" \) -delete

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}/happydoclib
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}/happydoclib

post-build:
	@${ECHO_CMD} "bin/happydoc" > ${PLIST}
	@${FIND} ${WRKSRC}/happydoclib -type f | ${SORT} | ${SED} -e \
		's|${WRKSRC}|%%PYTHON_SITELIBDIR%%|' >> ${PLIST}
	@${FIND} ${WRKSRC}/happydoclib -type d | ${SORT} -r | ${SED} -e \
		's|${WRKSRC}|@dirrm %%PYTHON_SITELIBDIR%%|' >> ${PLIST}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/happydoc ${PREFIX}/bin
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} happydoclib ${PYTHON_SITELIBDIR})

.include <bsd.port.mk>
