# New ports collection makefile for:    icon
# Date created:         05 April 1995
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	icon
PORTVERSION=	9.4.0
CATEGORIES=	lang
MASTER_SITES=	http://www.cs.arizona.edu/icon/ftp/packages/unix/
DISTNAME=	${PORTNAME}.v${PORTVERSION:S/.//g}src
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	The Icon programming language

ONLY_FOR_ARCHS=	alpha i386

.ifdef WITHOUT_X11
CONFIG_CMD=	Configure
PLIST_SUB=	WITHOUT_X11="@comment "
.else
USE_XLIB=	yes
CFLAGS+=	-I${X11BASE}/include
CONFIG_CMD=	X-Configure
PLIST_SUB=	WITHOUT_X11=
.endif
USE_REINPLACE=	yes
ALL_TARGET=	All

MAN1=		icont.1

ARCH_NAME=	${ARCH:S/i386/intel/}_${OPSYS:L}
ICONDIR=	${PREFIX}/lib/${PORTNAME}

pre-patch:
	@${REINPLACE_CMD} -e "s|^CC.*|CC=${CC}|g ; \
		 s|^CFLAGS.*|CFLAGS=${CFLAGS}|g ; \
		 s|^XLIBS.*|XLIBS=-L${X11BASE}/lib -lX11|g" \
		${WRKSRC}/config/unix/${ARCH_NAME}/Makedefs
	@${REINPLACE_CMD} -e 's|/opt/icon|${ICONDIR}|g' ${WRKSRC}/ipl/BuildBin

do-configure:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${CONFIG_CMD} name=${ARCH_NAME})

do-install:
	${INSTALL_MAN} ${WRKSRC}/man/man1/icont.1 ${PREFIX}/man/man1
	@${MKDIR} ${ICONDIR}/bin
.for file in icont iconx patchstr
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${file} ${ICONDIR}/bin
.endfor
.ifndef WITHOUT_X11
.for file in colrbook colrpick fontpick ipatch palette vib wevents xgamma
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${file} ${ICONDIR}/bin
.endfor
.endif
.for file in icont iconx
	@${LN} -sf ${ICONDIR}/bin/${file} ${PREFIX}/bin/${file}
.endfor
.ifndef WITHOUT_X11
	@${LN} -sf ${ICONDIR}/bin/vib ${PREFIX}/bin/vib
.endif
	@${MKDIR} ${ICONDIR}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/*.* ${ICONDIR}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.* ${DOCSDIR}
.endif

.include <bsd.port.mk>
