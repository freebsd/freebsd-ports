# $FreeBSD$

PORTNAME=	gcvs
PORTVERSION=	1.0
PORTREVISION=	15
PORTEPOCH=	1
CATEGORIES=	devel tk
MASTER_SITES=	SF/cvsgui/gCvs/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High-end interface client for CVS

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GNOME=	gtk12
USES=		autoreconf gmake tk:wrapper,tea
CXXFLAGS:=	${CXXFLAGS:N-std=*:N:}
EXTRACT_AFTER_ARGS=--exclude cvsunix --exclude 'getline.[ch]' --exclude 'getopt*.[ch]'

post-patch:
	${REINPLACE_CMD} -E '/get(line|opt1?)\.[ch]/d'	\
		${WRKSRC}/common/Makefile.am
	${FIND} ${WRKSRC} -name '*.c*' | ${XARGS} ${REINPLACE_CMD} -E	\
		-e '/#include "getline\.h"/d' \
		-e 's/"getopt\.h"/<getopt.h>/'
	${REINPLACE_CMD} 's/cvsunix//g'	\
		${WRKSRC}/Makefile.am ${WRKSRC}/configure.in

.include <bsd.port.mk>
