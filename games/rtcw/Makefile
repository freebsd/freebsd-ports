# New ports collection makefile for:	Return to Castle Wolfenstein
# Date created:				Sun Jun  3 00:52:38 EDT 2001
# Whom:					nik@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	rtcw
PORTVERSION=	1.1b
PORTREVISION=	2
CATEGORIES=	games linux
MASTER_SITES=	ftp://ftp.idsoftware.com/idstuff/wolf/linux/old/
DISTNAME=	wolf-linux-${PORTVERSION}.x86
EXTRACT_SUFX=	.run

MAINTAINER=	nik@FreeBSD.org
COMMENT=	Return to Castle Wolfenstein for Linux

BROKEN=		Incomplete pkg-plist
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_X_PREFIX=	yes
NO_CDROM=	"Size; the data set is much too big"
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_PERL5_BUILD=yes
RTCWDIR=	games/rtcw
PLIST_SUB+=	RTCWDIR="${RTCWDIR}"
INSTALL_DIR=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 755

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && tail +175 ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
		${TAR} zxvf - >/dev/null

pre-patch:
# remove trailing ^M
	@${FIND} -E ${WRKSRC} -type f \
		-iregex ".*\.(bat|cfg|gam|htm|html|inf|ini|lst|sc|scr|txt|url)" \
		-exec ${PERL} -pi -ne 's!\r\n!\n!' {} 1>/dev/null 2>&1 \;

do-install:
	${INSTALL_DIR} ${PREFIX}/${RTCWDIR}
.for file in CHANGES INSTALL QUICKSTART WolfMP.xpm WolfSP.xpm
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/${RTCWDIR}
.endfor
.for file in openurl.sh
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${PREFIX}/${RTCWDIR}
.endfor
.for file in wolf.x86 wolfded.x86 wolfsp.x86
	${INSTALL} -c -m 500 ${WRKSRC}/bin/x86/${file} ${PREFIX}/${RTCWDIR}
.endfor
	${INSTALL_DIR} ${PREFIX}/${RTCWDIR}/main
.for file in cgame.mp.i386.so cgamei386.so mp_pakmaps0.pk3 qagame.mp.i386.so qagamei386.so rotate.cfg ui.mp.i386.so uii386.so
	${INSTALL_DATA} ${WRKSRC}/main/${file} ${PREFIX}/${RTCWDIR}/main
.endfor
	${INSTALL_DIR} ${PREFIX}/${RTCWDIR}/main/scripts
	${INSTALL_DATA} ${WRKSRC}/main/scripts/translation.cfg ${PREFIX}/${RTCWDIR}/main/scripts

# XXX Should really install the Docs/ directory as well
post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
