# New ports collection makefile for:	Quake 3 Arena Dedicated Server
# Date created:				Sun Jun  3 00:52:38 EDT 2001
# Whom:					pat@databits.net
#
# $FreeBSD$
#

PORTNAME=	q3ded
PORTVERSION=	1.30
CATEGORIES=	games linux
MASTER_SITES=	http://fileplanet.games-world.net/dl/ftp1.gamespy.com/fpnew/action/quake3/official/ \
		ftp://ftp.idsoftware.com/idstuff/quake3/linux/ \
		ftp://ftp.bluesnews.com/idstuff/quake3/linux/
DISTNAME=	linuxq3apoint-${PORTVERSION}.x86
EXTRACT_SUFX=	.run

MAINTAINER=	pat@databits.net

ONLY_FOR_ARCHS=	i386
USE_LINUX_PREFIX=	yes
NO_CDROM=	"Size; the data set is much too big"
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
Q3DIR=		usr/games/quake3/
PLIST_SUB+=	Q3DIR="${Q3DIR}"
INSTALL_DIR=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 755

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && tail +175 ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
		${TAR} zxvf - >/dev/null

pre-patch:
# remove trailing ^M
	@find -E ${WRKSRC} -type f \
		-iregex ".*\.(bat|cfg|gam|htm|html|inf|ini|lst|sc|scr|txt|url)" \
		-exec ${PERL} -pi -ne 's!\r\n!\n!' {} 1>/dev/null 2>&1 \;

do-install:
	@${INSTALL_DIR} ${PREFIX}/${Q3DIR}
	@${INSTALL_DIR} ${PREFIX}/${Q3DIR}baseq3
	@${INSTALL_DIR} ${PREFIX}/${Q3DIR}missionpack
	@${INSTALL_DATA} ${WRKSRC}/baseq3/pak1.pk3 ${PREFIX}/${Q3DIR}baseq3
	@${INSTALL_DATA} ${WRKSRC}/baseq3/pak2.pk3 ${PREFIX}/${Q3DIR}baseq3
	@${INSTALL_DATA} ${WRKSRC}/baseq3/pak3.pk3 ${PREFIX}/${Q3DIR}baseq3
	@${INSTALL_DATA} ${WRKSRC}/baseq3/pak4.pk3 ${PREFIX}/${Q3DIR}baseq3
	@${INSTALL_DATA} ${WRKSRC}/baseq3/pak5.pk3 ${PREFIX}/${Q3DIR}baseq3
	@${INSTALL_DATA} ${WRKSRC}/baseq3/pak6.pk3 ${PREFIX}/${Q3DIR}baseq3
	@${INSTALL_DATA} ${WRKSRC}/missionpack/pak1.pk3 ${PREFIX}/${Q3DIR}missionpack
	@${INSTALL} -c -o nobody -g nogroup -m 500 ${WRKSRC}/bin/x86/q3ded ${PREFIX}/${Q3DIR}
	@${INSTALL} -c -o nobody -g nogroup -m 500 ${WRKSRC}/bin/x86/quake3.x86 ${PREFIX}/${Q3DIR}

post-install:
.ifndef(NOPORTDOCS)
	@${INSTALL_DIR} ${PREFIX}/${Q3DIR}Help
	@${INSTALL_DATA} ${WRKSRC}/Help/Q3A_FAQ.html ${PREFIX}/${Q3DIR}Help
	@${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/${Q3DIR}
	@${INSTALL_DATA} ${WRKSRC}/Q3A_EULA.txt ${PREFIX}/${Q3DIR}
	@${INSTALL_DATA} ${WRKSRC}/README-Id-7-26-01.html ${PREFIX}/${Q3DIR}
	@${INSTALL_DATA} ${WRKSRC}/README-linux.txt ${PREFIX}/${Q3DIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
