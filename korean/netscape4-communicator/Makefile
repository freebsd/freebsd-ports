# New ports collection makefile for: Netscape browser with Korean resources
# Version required:	4.08
# Date created:		25 Oct 1998
# Whom:			CHOI Junho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.9 1998/12/13 22:00:40 kuriyama Exp $
#
# based on japanese/netscape4-*

DISTNAME=	ko-netscape-${BROWSER}
CATEGORIES=	korean www
MASTER_SITES=	ftp://jazz.snu.ac.kr/pub/unix/netscape-ko/
DISTFILES=	${KOREAN_KIT}.tar.gz

MAINTAINER?=	junker@jazz.snu.ac.kr

RUN_DEPENDS= \
	${PREFIX}/bin/${BROWSER}:${PORTSDIR}/www/netscape4-${BROWSER_NAME} \
	${X11BASE}/lib/X11/fonts/local/hgm12.pcf.gz:${PORTSDIR}/korean/hanyangfonts \
	${X11BASE}/lib/X11/fonts/local/mzgt16h1.pcf.gz:${PORTSDIR}/korean/mizifont

NO_BUILD=	yes
STRIP=
WRKSRC=		${WRKDIR}/${KOREAN_KIT}

BROWSER=	${BROWSER_NAME}-${BROWSER_VER}
BROWSER_NAME?=	communicator
BROWSER_VER=	4.08
LANG=		ko_KR.EUC
KOREAN_KIT=	netscape-v408.generic-generic-generic-19981227
NDIR=		${PREFIX}/lib/netscape
MAKESCRIPT=	${SED} -e "s;@X11BASE@;${X11BASE};g" \
			-e "s;@PREFIX@;${PREFIX};g" \
			-e "s;@NDIR@;${NDIR};g" \
			-e "s;@RDIR@;${NDIR};g" \
			-e "s;@BROWSER@;${BROWSER};g" \
			-e "s;@LANG@;${LANG};g"
TAR=		/usr/bin/tar

.SILENT:

do-configure:
	${MAKESCRIPT} ${FILESDIR}/start.sh.in >${WRKDIR}/start.sh
	${MAKESCRIPT} ${WRKSRC}/Netscape.ad-ko >${WRKSRC}/Netscape

do-install:
	${INSTALL_DATA} ${FILESDIR}/preferences.js ${NDIR}
	${MKDIR} ${NDIR}/locale
	${LN} -sf /usr/share/locale/en_US.ISO_8859-1 ${NDIR}/locale/${LANG}
	${MKDIR} ${NDIR}/${LANG}
.for f in Netscape about mail.msg netscape.cfg plugins \
	  splash LICENSE.ko
	${INSTALL_DATA} ${WRKSRC}/$f ${NDIR}/${LANG}/
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/start.sh ${PREFIX}/bin/ko-${BROWSER}
	${LN} -sf ko-${BROWSER} ${PREFIX}/bin/netscape
	${TAR} -C ${NDIR}/${LANG} -x -z -v -f ${WRKSRC}/nethelp-v403.nif

.include <bsd.port.mk>
