# New ports collection makefile for:	Quake 3 Arena Dedicated Server
# Date created:				Sun Jun  3 00:52:38 EDT 2001
# Whom:					pat@databits.net
#
# $FreeBSD$
#

PORTNAME=	q3ded
PORTVERSION=	1.32b
PORTREVISION=	1
CATEGORIES=	games linux
MASTER_SITES=	ftp://ftp.bluesnews.com/idstuff/quake3/linux/ \
		ftp://ftp.idsoftware.com/idstuff/quake3/linux/
DISTNAME=	linuxq3apoint-${PORTVERSION}.x86
EXTRACT_SUFX=	.run

MAINTAINER=	pat@FreeBSD.org
COMMENT=	Quake III Arena Dedicated Server for Linux

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_PERL5=	yes
NO_CDROM=	"Size; the data set is much too big"
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
Q3BASE=		games
Q3DIR=		${Q3BASE}/quake3/
PLIST_SUB+=	Q3DIR="${Q3DIR}" Q3BASE="${Q3BASE}"
INSTALL_DIR=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 755

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && ${TAIL} +266 ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
		${TAR} zxvf - >/dev/null

pre-patch:
# remove trailing ^M
	@${FIND} -E ${WRKSRC} -type f \
		-iregex ".*\.(bat|cfg|gam|htm|html|inf|ini|lst|sc|scr|txt|url)" \
		-exec ${PERL} -pi -ne 's!\r\n!\n!' {} 1>/dev/null 2>&1 \;

do-install:
	@${INSTALL_DIR} ${PREFIX}/${Q3DIR}/pb ${PREFIX}/${Q3DIR}/baseq3 \
		${PREFIX}/${Q3DIR}/missionpack
.for bpak in 1 2 3 4 5 6 7 8
	@${INSTALL_DATA} ${WRKSRC}/baseq3/pak${bpak}.pk3 \
		${PREFIX}/${Q3DIR}/baseq3
.endfor
.for mpak in 1 2 3
	@${INSTALL_DATA} ${WRKSRC}/missionpack/pak${mpak}.pk3 \
		${PREFIX}/${Q3DIR}/missionpack
.endfor
.for exec in q3ded quake3.x86 quake3-smp.x86
	@${INSTALL} -c -o nobody -g nogroup -m 500 ${WRKSRC}/bin/x86/${exec} \
		${PREFIX}/${Q3DIR}
.endfor
.for pb in pbag.so pbcl.so pbsv.so
	@${INSTALL_DATA} ${WRKSRC}/pb/${pb} ${PREFIX}/${Q3DIR}/pb
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL_DIR} ${PREFIX}/${Q3DIR}/Docs/LinuxFAQ \
		${PREFIX}/${Q3DIR}/Docs/PunkBuster/admins \
		${PREFIX}/${Q3DIR}/Docs/PunkBuster/players \
		${PREFIX}/${Q3DIR}/pb/htm
.for docs in CHANGES-1.32.txt INSTALL Q3A_EULA.txt README-Id-7-26-01.html \
	README-linux.txt quake3.xpm
	@${INSTALL_DATA} ${WRKSRC}/${docs} ${PREFIX}/${Q3DIR}
.endfor
.for faq in INSTALL index.html udp_wide_README.txt udp_wide_broadcast.patch
	@${INSTALL_DATA} ${WRKSRC}/Docs/LinuxFAQ/${faq} \
		${PREFIX}/${Q3DIR}/Docs/LinuxFAQ
.endfor
.for admins in index.htm tabout1.gif tadvanced1.gif tbasics1.gif \
	tcommands1.gif tcommands2.gif tenabling1.gif tfaq1.gif tgame1.gif \
	tintro1.gif tlogo.gif tmonitoring1.gif tpbint1.gif tpbsub1.gif \
	tplayer1.gif tquick1.gif tremote1.gif tscreen1.gif tsettings1.gif \
	ttitle1.gif ttoc1.gif tupdating1.gif
	@${INSTALL_DATA} ${WRKSRC}/Docs/PunkBuster/admins/${admins} \
		${PREFIX}/${Q3DIR}/Docs/PunkBuster/admins
.endfor
.for players in index.htm sbrowser1.jpg skeyboard1.gif stilde1.gif tabout1.gif \
	tbasics1.gif tbutton1.gif tbutton2.gif tcommands1.gif tcommands2.gif \
	tenabling1.gif tfaq1.gif tfinding1.gif tgame1.gif tintro1.gif \
	tlogo.gif tmonitoring1.gif tname1.gif tpbint1.gif tpbsub1.gif \
	tquick1.gif tremote1.gif tscreen1.gif tsettings1.gif ttaking1.gif \
	ttitle1.gif ttoc1.gif tupdating1.gif tusing1.gif
	@${INSTALL_DATA} ${WRKSRC}/Docs/PunkBuster/players/${players} \
		${PREFIX}/${Q3DIR}/Docs/PunkBuster/players
.endfor
.for pbhtm in la001293.htm lc000993.htm ls000993.htm ma001293.htm mc000993.htm \
	ms000993.htm wa001293.htm wc000993.htm ws000993.htm
	@${INSTALL_DATA} ${WRKSRC}/pb/htm/${pbhtm} ${PREFIX}/${Q3DIR}/pb/htm
.endfor
	@${INSTALL_DATA} ${WRKSRC}/pb/PB_EULA.txt ${PREFIX}/${Q3DIR}/pb
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
