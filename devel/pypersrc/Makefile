# New ports collection makefile for:	pypersrc
# Date created:		18 Apr 2006
# Whom:			Joseph Koshy <jkoshy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pypersrc
PORTVERSION=	20120106
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.jimbrooks.org/pypersrc/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python/Tkinter based source browser

BUILD_DEPENDS=	exctags:${PORTSDIR}/devel/ctags \
		${PYTHON_SITELIBDIR}/Pmw:${PORTSDIR}/x11-toolkits/py-Pmw
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_BZIP2=	yes
USE_PYTHON=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.sh

PLIST_FILES=	bin/pypersrc.py bin/pypersrc2.py bin/pypersrc

post-patch:
	${REINPLACE_CMD} -e 's|/bin/bash|${SH}|g' \
	    ${WRKSRC}/configure.sh

.include <bsd.port.mk>
