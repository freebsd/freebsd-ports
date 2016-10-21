# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	unmakeself
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	archivers
DISTFILES=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extract Makeself archives

USES=		libarchive
LIBS+=		-larchive
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/unmakeself

do-configure:
	@${RM} ${WRKSRC}/config.h
	@if ${GREP} -q memmem /usr/include/string.h; then \
		${ECHO_CMD} "#define HAS_MEMMEM" > ${WRKSRC}/config.h; \
	else \
		${ECHO_CMD} "#undef HAS_MEMMEM" > ${WRKSRC}/config.h; \
	fi

do-build:
	${CC} ${CFLAGS} ${CPPFLAGS} -I${WRKSRC} -o ${WRKSRC}/unmakeself \
		${FILESDIR}/unmakeself.c ${LDFLAGS} ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unmakeself ${STAGEDIR}/${PREFIX}/bin

.include <bsd.port.mk>
