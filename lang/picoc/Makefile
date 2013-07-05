# Created by: Bapt <bapt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	picoc
PORTVERSION=	2.1
CATEGORIES=	lang devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Very small C interpreter for scripting

LICENSE=	BSD

USES=		gmake
USE_BZIP2=	yes

PLIST_FILES=	bin/picoc

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e "/-include/d" \
		-e "s/^CFLAGS=.*/CFLAGS=${CFLAGS} -DUNIX_HOST/" \
		-e "s/gcc/${CC}/" \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/picoc ${PREFIX}/bin/picoc

.include <bsd.port.mk>
