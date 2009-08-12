# New ports collection makefile for:    icon
# Date created:         05 April 1995
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	icon
PORTVERSION=	9.4.3
PORTREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	http://www.cs.arizona.edu/icon/ftp/packages/unix/
DISTNAME=	${PORTNAME}.v${PORTVERSION:S/.//g}src
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Icon programming language

ALL_TARGET=	All
MAKE_JOBS_UNSAFE=	yes

MAN1=		icon.1 icont.1

ARCH_NAME=	bsd
ICONDIR=	${PREFIX}/lib/${PORTNAME}

BINS=		icont iconx rtt
BINXS=		colrbook colrpick fontpick palette vib wevents xgamma

.if defined(WITHOUT_X11)
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
		 s|-lpthread|${PTHREAD_LIBS}| ; \
		 s|^XLIBS.*|XLIBS=-L${LOCALBASE}/lib -lX11|g" \
		${WRKSRC}/config/${ARCH_NAME}/Makedefs
	@${REINPLACE_CMD} -e 's|/opt/icon|${ICONDIR}|g' ${WRKSRC}/ipl/BuildBin
	@${REINPLACE_CMD} -e 's|ld -Bshareable|\$$CC -shared|g ; \
		 s|-lc||g' ${WRKSRC}/ipl/cfuncs/mklib.sh

do-configure:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${CONFIG_CMD} name=${ARCH_NAME})

do-install:
	${INSTALL_MAN} ${WRKSRC}/man/man1/icon.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/man1/icont.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${ICONDIR}/bin
.for file in ${BINS}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${file} ${ICONDIR}/bin/${file}
.endfor
.for file in icont iconx
	@${LN} -sf ${ICONDIR}/bin/${file} ${PREFIX}/bin/${file}
.endfor
	@${LN} -sf ${ICONDIR}/bin/icont ${PREFIX}/bin/icon
	@${MKDIR} ${ICONDIR}/lib
	cd ${WRKSRC}/lib; ${INSTALL_DATA} *.* ${ICONDIR}/lib
.if !defined(WITHOUT_X11)
.for file in ${BINXS}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${file} ${ICONDIR}/bin/${file}
.endfor
	@${LN} -sf ${ICONDIR}/bin/vib ${PREFIX}/bin/vib
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.* ${DOCSDIR}
.endif

.if defined(MAINTAINER_MODE)
test:	install
	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} Test)
.endif

.include <bsd.port.mk>
