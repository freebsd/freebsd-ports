# New ports collection makefile for:	ssamtse
# Date created:				25 November 2003
# Whom:					Sergey Akifyev
#
# $FreeBSD$
#

PORTNAME=	ssamtse
PORTVERSION=	1.07b1
CATEGORIES=	games linux
MASTER_SITES=	http://liflg.0wnitsch.de/files/final/
PKGNAMEPREFIX=	linux-
DISTFILES=	${PORTNAME:S|ssam|serious.sam.|}_${PORTVERSION:S|b|beta|}-english-2.run

MAINTAINER=	avl@FreeBSD.org
COMMENT=	Serious Sam: The Second Encounter for Linux

OPTIONS=	VORBIS	"Ogg playing support"	on

USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
NO_BUILD=	yes
NO_PACKAGE=	Distribution is 352MB; set FORCE_PACKAGE if you really want to build this package
RESTRICTED=	Redistribution is limited, see license
PORTDOCS=	README.liflg ShellSymbols.txt changes.txt Notes_1_04.txt
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if defined(WITH_VORBIS)
USE_LINUX_APPS+=libvorbis
PLIST_SUB+=	VORBIS=""
.else
PLIST_SUB+=	VORBIS="@comment "
.endif

# Gold Edition
.if exists(${CDROM_MOUNT}/Install/SEGold_DM.gro)
PLIST_SUB+=	GOLD=""
.else
PLIST_SUB+=	GOLD="@comment "
.endif

do-extract:
	@${MKDIR} ${WRKSRC}/Data
	@cd ${WRKSRC} && ${SED} -e '1,/exit $$res/d' ${_DISTDIR}/${DISTFILES} |\
		${GUNZIP_CMD} -q | ${TAR} xf -
	@${TAR} jx -C ${WRKSRC}/Data -f ${WRKSRC}/bins.tar.bz2

post-patch:
	@${REINPLACE_CMD} -e "s|^\(GAMEDIR=\).*|\1\"${DATADIR}\"|" \
		-e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/bin/${PORTNAME}

do-install:
.if !defined(CDROM_MOUNT)
	@${ECHO_CMD} "${PKGNAME} requires CDROM_MOUNT set to mount point of CD"
	@${FALSE}
.endif
.if !exists(${CDROM_MOUNT}/Install/Mods/SecondEncounterTbn.tex)
	@${ECHO_CMD} "${PKGNAME} requires a retail Second Encounter disc"
	@${FALSE}
.endif
	@${MKDIR} ${DATADIR}/Mods
.for gro in "" _Extra _ExtraTools _Levels _Music
	${INSTALL_DATA} "${CDROM_MOUNT}/Install/SE1_00${gro}.gro" ${DATADIR}/SE1_00${gro}.gro
.endfor
	${INSTALL_DATA} "${CDROM_MOUNT}/Install/Mods/SecondEncounterTbn.tex" ${DATADIR}/Mods/SecondEncounterTbn.tex
.for dir in Controls Data Scripts VirtualTrees Worlds Demos
	@cd ${CDROM_MOUNT}/Install && \
		${FIND} ${dir} -type d -exec \
			${MKDIR} "${DATADIR}/{}" \; && \
		${FIND} ${dir} -type f -exec \
			${INSTALL_DATA} "${CDROM_MOUNT}/Install/{}" "${DATADIR}/{}" \;
.endfor
	@${MKDIR} ${DATADIR}/Help
.for i in ${PORTDOCS:NREADME.liflg}
	${INSTALL_DATA} "${CDROM_MOUNT}/Install/Help/${i}" ${DATADIR}/Help/${i}
.endfor
.for dir in Data/Var Levels
	@cd ${WRKSRC} && \
		${FIND} ${dir} -type d -exec \
			${MKDIR} "${DATADIR}/{}" \; && \
		${FIND} ${dir} -type f -exec \
			${INSTALL_DATA} "${WRKSRC}/{}" "${DATADIR}/{}" \;
.endfor
	@${MKDIR} ${DATADIR}/Bin
	@cd ${WRKSRC}/Data && \
		${FIND} Bin -type f -exec \
			${INSTALL_PROGRAM} "${WRKSRC}/Data/{}" "${DATADIR}/{}" \;
	${BRANDELF} -t Linux ${DATADIR}/Bin/ssam_*
	${INSTALL_DATA} ${WRKSRC}/ModExt.txt ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin
.if defined(WITH_VORBIS)
	${LN} -fs ${LINUXBASE}/usr/lib/libvorbisfile.so.3 ${DATADIR}/Bin/libvorbisfile.so
.endif
	@${FIND} -E ${DATADIR} -type f \
		-iregex ".*\.(ctl|txt|lst|ini|cfg|des|reg)" \
		! -iregex ".*ModExt.txt" \
		-exec ${SH} -c "${SED} "s/`printf '\r'`//" '{}' \
		>${WRKDIR}/tmp.txt; ${MV} ${WRKDIR}/tmp.txt '{}'" \;
	@${ECHO} SERIOUS_MHZ=2000 > ${PREFIX}/etc/${PORTNAME}.conf.sample
.if !exists(${PREFIX}/etc/${PORTNAME}.conf)
	${INSTALL_DATA} ${PREFIX}/etc/${PORTNAME}.conf.sample ${PREFIX}/etc/${PORTNAME}.conf
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} -p ${WRKSRC}/README.liflg ${DOCSDIR}
.for i in ${PORTDOCS:NREADME.liflg}
	${LN} -sf ${DATADIR}/Help/${i} ${DOCSDIR}/${i}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
