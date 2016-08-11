# Created by: Sergey Akifyev
# $FreeBSD$

PORTNAME=	ssamtse
PORTVERSION=	1.07b1
CATEGORIES=	games linux
MASTER_SITES=	http://home.coc-ag.de/dressler-ro/liflg/files/final/ \
		http://bsd-geek.de/FreeBSD/distfiles/
PKGNAMEPREFIX=	linux-
DISTFILES=	${PORTNAME:S|ssam|serious.sam.|}_${PORTVERSION:S|b|beta|}-english-2.run

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Serious Sam: The Second Encounter for Linux

OPTIONS_DEFINE=	VORBIS DOCS
OPTIONS_DEFAULT=	VORBIS

USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
NO_BUILD=	yes
RESTRICTED=	Redistribution is limited, see license
PORTDOCS=	README.liflg ShellSymbols.txt changes.txt Notes_1_04.txt
SUB_FILES=	pkg-message

.if !defined(CDROM_MOUNT)
IGNORE=		${PKGNAME} requires CDROM_MOUNT set to mount point of CD
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVORBIS}
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
.if !exists(${CDROM_MOUNT}/Install/Mods/SecondEncounterTbn.tex)
	@${ECHO_CMD} "${PKGNAME} requires a retail Second Encounter disc"
	@${FALSE}
.endif
	@${MKDIR} ${STAGEDIR}${DATADIR}/Mods
.for gro in "" _Extra _ExtraTools _Levels _Music
	${INSTALL_DATA} "${CDROM_MOUNT}/Install/SE1_00${gro}.gro" ${STAGEDIR}${DATADIR}/SE1_00${gro}.gro
.endfor
	${INSTALL_DATA} "${CDROM_MOUNT}/Install/Mods/SecondEncounterTbn.tex" ${STAGEDIR}${DATADIR}/Mods/SecondEncounterTbn.tex
.for dir in Controls Data Scripts VirtualTrees Worlds Demos
	@cd ${CDROM_MOUNT}/Install && \
		${FIND} ${dir} -type d -exec \
			${MKDIR} "${STAGEDIR}${DATADIR}/{}" \; && \
		${FIND} ${dir} -type f -exec \
			${INSTALL_DATA} "${CDROM_MOUNT}/Install/{}" "${STAGEDIR}${DATADIR}/{}" \;
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}/Help
.for i in ${PORTDOCS:NREADME.liflg}
	${INSTALL_DATA} "${CDROM_MOUNT}/Install/Help/${i}" ${STAGEDIR}${DATADIR}/Help/${i}
.endfor
.for dir in Data/Var Levels
	@cd ${WRKSRC} && \
		${FIND} ${dir} -type d -exec \
			${MKDIR} "${STAGEDIR}${DATADIR}/{}" \; && \
		${FIND} ${dir} -type f -exec \
			${INSTALL_DATA} "${WRKSRC}/{}" "${STAGEDIR}${DATADIR}/{}" \;
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}/Bin
	@cd ${WRKSRC}/Data && \
		${FIND} Bin -type f -exec \
			${INSTALL_PROGRAM} "${WRKSRC}/Data/{}" "${STAGEDIR}${DATADIR}/{}" \;
	${BRANDELF} -t Linux ${STAGEDIR}${DATADIR}/Bin/ssam_*
	${INSTALL_DATA} ${WRKSRC}/ModExt.txt ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MVORBIS}
	${LN} -fs ${LINUXBASE}/usr/lib/libvorbisfile.so.3 ${STAGEDIR}${DATADIR}/Bin/libvorbisfile.so
.endif
	@${FIND} -E ${STAGEDIR}${DATADIR} -type f \
		-iregex ".*\.(ctl|txt|lst|ini|cfg|des|reg)" \
		! -iregex ".*ModExt.txt" \
		-exec ${SH} -c "${SED} "s/`printf '\r'`//" '{}' \
		>${WRKDIR}/tmp.txt; ${MV} ${WRKDIR}/tmp.txt '{}'" \;
	@${ECHO} SERIOUS_MHZ=2000 > ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample
.if !exists(${PREFIX}/etc/${PORTNAME}.conf)
	${INSTALL_DATA} ${PREFIX}/etc/${PORTNAME}.conf.sample ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} -p ${WRKSRC}/README.liflg ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS:NREADME.liflg}
	${LN} -sf ${DATADIR}/Help/${i} ${STAGEDIR}${DOCSDIR}/${i}
.endfor
.endif

.include <bsd.port.mk>
