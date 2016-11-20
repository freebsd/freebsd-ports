# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	icon
PORTVERSION=	9.5.1
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.cs.arizona.edu/icon/ftp/packages/unix/
DISTNAME=	${PORTNAME}-v${PORTVERSION:S/.//g}src
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Icon programming language

USE_GCC=	any
ALL_TARGET=	All
MAKE_JOBS_UNSAFE=	yes
ARCH_NAME=	bsd
ICONDIR=	${PREFIX}/lib/${PORTNAME}

BINS=		icont iconx
BINXS=		colrbook colrpick fontpick palette vib wevents xgamma

OPTIONS_DEFINE=	DOCS X11

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MX11)
CONFIG_CMD=	Configure
PLIST_SUB=	WITHOUT_X11="@comment "
.else
USE_XORG=	x11 xpm
CFLAGS+=	-I${LOCALBASE}/include
CONFIG_CMD=	X-Configure
PLIST_SUB=	WITHOUT_X11=
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|^CC.*|CC=${CC}|g ; \
		 s|^CFLAGS.*|CFLAGS=${CFLAGS}|g ; \
		 s|/usr/X11R6|${LOCALBASE}|g ; \
		 s|^XLIBS.*|XLIBS=-L${LOCALBASE}/lib -lX11|g" \
		${WRKSRC}/config/${ARCH_NAME}/Makedefs
	@${REINPLACE_CMD} -e 's|/opt/icon|${ICONDIR}|g' ${WRKSRC}/ipl/BuildBin
	@${REINPLACE_CMD} -e 's|ld -Bshareable|\$$CC -shared|g ; \
		 s|-lc||g' ${WRKSRC}/ipl/cfuncs/mklib.sh

do-configure:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${CONFIG_CMD} name=${ARCH_NAME})

do-install:
	${INSTALL_MAN} ${WRKSRC}/man/man1/icon.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/man1/icont.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${ICONDIR}/bin
.for file in ${BINS}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${file} ${STAGEDIR}${ICONDIR}/bin/${file}
.endfor
.for file in icont iconx
	@${LN} -sf ${ICONDIR}/bin/${file} ${STAGEDIR}${PREFIX}/bin/${file}
.endfor
	@${LN} -sf ${ICONDIR}/bin/icont ${STAGEDIR}${PREFIX}/bin/icon
	@${MKDIR} ${STAGEDIR}${ICONDIR}/lib
	cd ${WRKSRC}/lib; ${INSTALL_DATA} *.* ${STAGEDIR}${ICONDIR}/lib
.if ${PORT_OPTIONS:MX11}
.for file in ${BINXS}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${file} ${STAGEDIR}${ICONDIR}/bin/${file}
.endfor
	@${LN} -sf ${ICONDIR}/bin/vib ${STAGEDIR}${PREFIX}/bin/vib
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.* ${STAGEDIR}${DOCSDIR}

.if defined(MAINTAINER_MODE)
test:	install
	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} Test)
.endif

.include <bsd.port.mk>
