# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	aalib
PORTVERSION=	1.4.r5
PORTREVISION=	11
CATEGORIES=	graphics
MASTER_SITES=	SF/aa-project/aa-lib/1.4rc5
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/rc/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ASCII art library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	X11

USES=		libtool ncurses makeinfo
WRKSRC=		${WRKDIR}/${PORTNAME}-1.4.0
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INFO=		aalib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USE_XORG=	x11
CONFIGURE_ARGS=	--x-includes="${LOCALBASE}/include" \
		--x-libraries="${LOCALBASE}/lib"
.else
CONFIGURE_ARGS=	--with-x=no
.endif

post-extract:
	@${RM} -f ${WRKSRC}/doc/aalib.info*

post-patch:
	@${RM} -f ${WRKSRC}/config.cache
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g; \
		s|MAKEINFO=makeinfo|MAKEINFO="makeinfo --no-split"|g ; \
		s|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} \
		-e 's|AC_DEFUN(AM_PATH_AALIB|AC_DEFUN([AM_PATH_AALIB]|g' \
		${WRKSRC}/aalib.m4
	@${FIND} ${WRKSRC} \( -name '*.[ch]' \! -name acconfig.h \) \
		| ${XARGS} ${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|g'

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libaa.so

.include <bsd.port.mk>
