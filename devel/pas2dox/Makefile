# Ports collection makefile for:	pas2dox
# Date created:				2006-03-16
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=	pas2dox
DISTVERSION=	0.50rc1
CATEGORIES=	devel converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	andreas@syndrom23.de
COMMENT=	Preprocessor to use doxygen with Pascal sources

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/pas2dox

post-patch:
	${REINPLACE_CMD} 's,^CC=.*$$,CC=$${CXX} $${CPPFLAGS} $${CXXFLAGS},' ${WRKSRC}/Makefile

pre-build:
	${MAKE} -C ${WRKSRC} clean

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/pas2dox ${PREFIX}/bin

.include <bsd.port.mk>
