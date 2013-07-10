# $FreeBSD$

PORTNAME=	ucon64
PORTVERSION=	2.0.0
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME:L}/${PORTNAME:L}-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	root@cooltrainer.org
COMMENT=	Multipurpose video game ROM image and backup utility

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}-src/src

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/ucon64.c
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/ucon64_misc.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/libdiscmage/discmage.so ${PREFIX}/lib/libdiscmage.so

PLIST_FILES=	bin/ucon64 \
	lib/libdiscmage.so

.include <bsd.port.mk>
