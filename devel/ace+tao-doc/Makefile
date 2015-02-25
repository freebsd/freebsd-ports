# Created by: Sergey Matveychuk <sem@ciam.ru>
# $FreeBSD$

PORTNAME=	ace+tao-doc
PORTVERSION=	5.5.0
CATEGORIES=	devel
MASTER_SITES=	ftp://download.dre.vanderbilt.edu/previous_versions/ \
		http://download.dre.vanderbilt.edu/previous_versions/
DISTNAME=	ACE-${PORTVERSION:C/\.0$//}-html

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The ACE+TAO HTML documentation

USES=		tar:bzip2
WRKSRC=		${WRKDIR}/html
NO_BUILD=	yes
NO_ARCH=	yes
PLIST=		${WRKDIR}/pkg-plist
DIRLIST=	${WRKDIR}/dir-list
INSTALL_DIR=	share/doc/${PORTNAME}

pre-install:
	cd ${WRKSRC} && ${FIND} -s . -type f | ${SED} -e 's|^\./|${INSTALL_DIR}/|' >> ${PLIST}

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
