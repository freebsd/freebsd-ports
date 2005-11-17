# New ports collection makefile for:	Quake 4
# Date created:				21 Oct 2005
# Whom:					Ed Schouten <ed@fxq.nl>
#
# $FreeBSD$
#

PORTNAME=	quake4
PORTVERSION=	1.0.5
PORTEPOCH=	1
CATEGORIES=	games linux
MASTER_SITES=	ftp://ftp.idsoftware.com/idstuff/quake4/linux/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-linux-${PORTVERSION}.x86
EXTRACT_SUFX=	.run

MAINTAINER=	infofarmer@gmail.com
COMMENT=	Quake 4 for Linux

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libSDL-1.2.so.0:${PORTSDIR}/devel/linux-sdl12

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes

NO_WRKSUBDIR=	yes

Q4DIR=		lib/${PORTNAME}/
PLIST_SUB+=	Q4DIR="${Q4DIR}"

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && ${TAIL} +376 ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
		${TAR} zxf -

do-build:
.for i in quake4 q4ded
	${BRANDELF} -t Linux ${WRKSRC}/bin/FreeBSD/x86/$i.x86

	# Startup scripts
	@${SED} \
		-e 's|@Q4DIR@|${PREFIX}/${Q4DIR}|' \
		-e 's|@APP@|$i.x86|' \
		${FILESDIR}/run.sh.in > ${WRKSRC}/$i.sh
.endfor

do-install:
	# Executables
	@${MKDIR} ${PREFIX}/${Q4DIR}
.for i in quake4 q4ded
	${INSTALL_SCRIPT} ${WRKSRC}/$i.sh ${PREFIX}/bin/$i
	${INSTALL_PROGRAM} ${WRKSRC}/bin/FreeBSD/x86/$i.x86 ${PREFIX}/${Q4DIR}/
.endfor

	# Punkbuster
	@${MKDIR} ${PREFIX}/${Q4DIR}/pb/htm
.for i in ag ags cl cls sv
	${INSTALL_DATA} ${WRKSRC}/pb/pb$i.so ${PREFIX}/${Q4DIR}/pb/
.endfor
.for i in l m w
	${INSTALL_DATA} ${WRKSRC}/pb/htm/$ia001307.htm ${PREFIX}/${Q4DIR}/pb/htm/
	${INSTALL_DATA} ${WRKSRC}/pb/htm/$ic001095.htm ${PREFIX}/${Q4DIR}/pb/htm/
.endfor

	# Q4base
	@${MKDIR} ${PREFIX}/${Q4DIR}/q4base
.for i in \
	arena_ctf.cfg ctf.cfg dm.cfg game100.pk4 \
	mapcycle.scriptcfg teamdm.cfg tourney.cfg

	${INSTALL_DATA} ${WRKSRC}/q4base/$i ${PREFIX}/${Q4DIR}/q4base/
.endfor

	# Documentation
.if !defined (NOPORTDOCS)
. for i in ENG ENU ESP FRA ITA
	@${MKDIR} ${DOCSDIR}/$i/images
	@${MKDIR} ${DOCSDIR}/$i/htm

.  for j in \
	License.txt MSR.txt PBEULA.txt help.htm htm/Default.htm \
	htm/credits.htm htm/cs.htm htm/left.htm htm/man_def.htm \
	htm/man_left.htm htm/man_top.htm htm/readme.htm \
	htm/side_ie.css htm/style_ie.css htm/techhelp.htm htm/top.htm \
	images/ATVIsmall.gif images/ATVIsmaller.jpg \
	images/Bink_Video_4c_rev.png images/ammo_regen.png \
	images/armor.png images/blaster.png images/doubler.png \
	images/guard.png images/h01.gif images/h02.gif images/h03.gif \
	images/h04.gif images/h05.gif images/h06.gif images/h07.gif \
	images/h08.gif images/h09.gif images/h10.gif images/h17a.gif \
	images/h17b.gif images/h26.gif images/h27.gif images/h28a.gif \
	images/h28b.gif images/h28c.gif images/h_def.gif \
	images/h_sup.gif images/h_tec.gif images/h_top.gif \
	images/haste.png images/health.png images/health_pack.png \
	images/id_logo_small.jpg images/ingamedisplay.png \
	images/invisibility.png images/line1.gif images/line1_b.gif \
	images/line2.gif images/line2_b.gif images/machinegun.png \
	images/mega_health.png images/mpbrowser.png images/mssLogo.png \
	images/pad.gif images/q4_logo_small.jpg images/quad_damage.png \
	images/raven.gif images/regeneration.png images/save.png \
	images/scout.png images/shotgun.png images/watermark.gif \
	manual.htm readme.txt

	${INSTALL_DATA} ${WRKSRC}/Docs/$i/$j ${DOCSDIR}/$i/$j
.  endfor
. endfor

	${INSTALL_DATA} ${WRKSRC}/License.txt ${DOCSDIR}/LICENSE
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/pb/PBEULA.txt ${DOCSDIR}/PBEULA
.endif

post-install:
	@${SED} 's|@DOCSDIR@|${DOCSDIR}|' ${PKGMESSAGE}

.include <bsd.port.mk>
