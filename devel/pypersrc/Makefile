# New ports collection makefile for:	pypersrc
# Date created:		18 Apr 2006
# Whom:			Joseph Koshy <jkoshy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pypersrc
PORTVERSION=	20120106
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.jimbrooks.org/pypersrc/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python/Tkinter based source browser

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE_GPL2.txt

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/Pmw:${PORTSDIR}/x11-toolkits/py-Pmw
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.sh
MAKE_ENV=	CXX_FLAGS="${CXXFLAGS}"

PLIST_FILES=	bin/pypersrc.py bin/pypersrc2.py bin/pypersrc

post-patch:
	@${REINPLACE_CMD} -e \
		'/INSTALL_DIR/s|=.*|=$$(PREFIX)/bin| ; \
		 /MAN_DIR/s|\/usr\/local|$$(PREFIX)| ; \
		 /-O2/s|^|#|' ${WRKSRC}/GNUmakefile
	@${REINPLACE_CMD} -e \
		's|/bin/bash|${SH}|g' ${WRKSRC}/configure.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out/pypersrc ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/out/pypersrc.py ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/out/pypersrc2.py ${PREFIX}/bin

.include <bsd.port.mk>
