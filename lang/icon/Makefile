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

ONLY_FOR_ARCHS=	alpha i386

USE_XLIB=	yes
USE_REINPLACE=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -I${X11BASE}/include" \
		XLIBS="-L${X11BASE}/lib -lX11"
ALL_TARGET=	All

MAN1=		icont.1

ARCH_NAME=	${ARCH:S/i386/intel/}_${OPSYS:L}
ICONDIR=	${PREFIX}/lib/${PORTNAME}

pre-patch:
	@${REINPLACE_CMD} -e 's|^CC|#CC|g ; \
		 s|^CFLAGS|#CFLAGS|g ; \
		 s|^XLIBS|#XLIBS|g' ${WRKSRC}/config/unix/${ARCH_NAME}/Makedefs
	@${REINPLACE_CMD} -e 's|/opt/icon|${ICONDIR}|g' ${WRKSRC}/ipl/BuildBin

do-configure:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} X-Configure name=${ARCH_NAME})

do-install:
	${INSTALL_MAN} ${WRKSRC}/man/man1/icont.1 ${PREFIX}/man/man1
	@${MKDIR} ${ICONDIR}/bin
.for file in icont iconx patchstr
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${file} ${ICONDIR}/bin
.endfor
.for file in colrbook colrpick fontpick ipatch palette vib wevents xgamma
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${file} ${ICONDIR}/bin
.endfor
.for file in icont iconx vib
	@${LN} -sf ${ICONDIR}/bin/${file} ${PREFIX}/bin/${file}
.endfor
	@${MKDIR} ${ICONDIR}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/*.* ${ICONDIR}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.* ${DOCSDIR}
.endif

.include <bsd.port.mk>
