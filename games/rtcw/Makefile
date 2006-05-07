# New ports collection makefile for:	Return to Castle Wolfenstein
# Date created:				Sun Jun  3 00:52:38 EDT 2001
# Whom:					nik@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	rtcw
DISTVERSION=	1.41-3
CATEGORIES=	games linux
MASTER_SITES=	${MASTER_SITE_IDSOFTWARE}
MASTER_SITE_SUBDIR=	wolf/linux
DISTNAME=	wolf-linux-${DISTVERSION}.x86
EXTRACT_SUFX=	.run

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Return to Castle Wolfenstein for Linux

ONLY_FOR_ARCHS=	i386

REINPLACE_ARGS=	-i ""
USE_LINUX=	yes
NO_WRKSUBDIR=	yes

SUB_FILES=	pkg-message

PROGS=		wolf wolfded wolfsp

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && tail +356 ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
		${TAR} zxf -

pre-patch:
	@# remove trailing ^M
	@${FIND} -E ${WRKSRC} -type f \
		-iregex ".*\.(bat|cfg|gam|htm|html|inf|ini|lst|sc|scr|txt|url)" \
		-exec ${REINPLACE_CMD} -e "s|`${ECHO_CMD} -e '\r'`$$||" {} \;

do-build:
.for f in ${PROGS}
	@(${ECHO_CMD} "#!${SH}"; \
		${ECHO_CMD} "cd ${DATADIR} || exit 1"; \
		${ECHO_CMD} "exec ./${f}") > ${WRKDIR}/${f}
.endfor

do-install:
	@${MKDIR} ${DATADIR}
.for f in ${PROGS}
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/Linux/x86/${f}.x86 ${DATADIR}/${f}
	@${INSTALL_SCRIPT} ${WRKDIR}/${f} ${PREFIX}/bin
.endfor
.for f in main pb
	@${CP} -R ${WRKSRC}/${f} ${DATADIR}
.endfor
	@${MKDIR} ${PREFIX}/share/pixmaps
.for f in WolfMP.xpm WolfSP.xpm
	@${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/pixmaps
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.   for f in CHANGES INSTALL QUICKSTART RTCW-README-1.4.txt
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.   endfor
	@${CP} -R ${WRKSRC}/Docs ${DOCSDIR}
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
