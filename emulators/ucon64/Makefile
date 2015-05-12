# $FreeBSD$

PORTNAME=	ucon64
PORTVERSION=	2.0.0
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME:tl}/${PORTNAME:tl}-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	root@cooltrainer.org
COMMENT=	Multipurpose video game ROM image and backup utility

USES=		gmake
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

WRKSRC_SUBDIR=		src

PLIST_FILES=	bin/ucon64 lib/libdiscmage.so

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/ucon64.c
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/ucon64_misc.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_LIB} ${WRKSRC}/libdiscmage/discmage.so \
		${STAGEDIR}${PREFIX}/lib/libdiscmage.so

.include <bsd.port.mk>
