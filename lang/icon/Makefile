# New ports collection makefile for:    icon
# Date created:         05 April 1995
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	icon
PORTVERSION=	9.4.1
CATEGORIES=	lang
MASTER_SITES=	http://www.cs.arizona.edu/icon/ftp/packages/unix/
DISTNAME=	${PORTNAME}.v${PORTVERSION:S/.//g}src
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Icon programming language

ONLY_FOR_ARCHS=	alpha i386

USE_REINPLACE=	yes
ALL_TARGET=	All

MAN1=		icont.1

ARCH_NAME=	${OPSYS:L}
ICONDIR=	${PREFIX}/lib/${PORTNAME}

.if defined(WITHOUT_X11)
CONFIG_CMD=	Configure
PLIST_SUB=	WITHOUT_X11="@comment "
.else
USE_XLIB=	yes
CFLAGS+=	-I${X11BASE}/include
CONFIG_CMD=	X-Configure
PLIST_SUB=	WITHOUT_X11=
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|^CC.*|CC=${CC}|g ; \
		 s|^CFLAGS.*|CFLAGS=${CFLAGS}|g ; \
		 s|^XLIBS.*|XLIBS=-L${X11BASE}/lib -lX11|g" \
		${WRKSRC}/config/unix/${ARCH_NAME}/Makedefs
	@${REINPLACE_CMD} -e 's|/opt/icon|${ICONDIR}|g' ${WRKSRC}/ipl/BuildBin
	@${REINPLACE_CMD} -e 's|ld -Bshareable|\$$CC -shared|g ; \
		 s|-lc||g' ${WRKSRC}/ipl/cfuncs/mklib.sh

do-configure:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${CONFIG_CMD} name=${ARCH_NAME})

do-install:
	${INSTALL_MAN} ${WRKSRC}/man/man1/icont.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${ICONDIR}/bin
.for file in icont iconx patchstr
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${file} ${ICONDIR}/bin/${file}
.endfor
.for file in icont iconx
	@${LN} -sf ${ICONDIR}/bin/${file} ${PREFIX}/bin/${file}
.endfor
	@${MKDIR} ${ICONDIR}/lib
	cd ${WRKSRC}/lib; ${INSTALL_DATA} *.* ${ICONDIR}/lib
.if !defined(WITHOUT_X11)
.for file in colrbook colrpick fontpick ipatch palette vib wevents xgamma
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${file} ${ICONDIR}/bin/${file}
.endfor
	@${LN} -sf ${ICONDIR}/bin/vib ${PREFIX}/bin/vib
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.* ${DOCSDIR}
.endif

.include <bsd.port.mk>
