# Created by: ijliao
# $FreeBSD$

PORTNAME=	sigslot
PORTVERSION=	1.0.0
CATEGORIES=	devel
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./-/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ Signal/Slot Library

PLIST_FILES=	include/sigslot.h
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

NO_STAGE=	yes
post-patch:
	@(cd ${WRKSRC} ; ${MV} -f sigslot.h sigslot.h.orig ; \
		${CAT} sigslot.h.orig | /usr/bin/col -b > sigslot.h)

do-install:
	${INSTALL_DATA} ${WRKSRC}/sigslot.h ${PREFIX}/include

.include <bsd.port.mk>
