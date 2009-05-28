# New ports collection makefile for:	linux-ssamtfe
# Date created:				18 May 2008
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	ssamtfe
PORTVERSION=	1.05b3
CATEGORIES=	games linux
MASTER_SITES=	http://liflg.0wnitsch.de/files/final/
PKGNAMEPREFIX=	linux-
DISTFILES=	${PORTNAME:S|ssam|serious.sam.|}_${PORTVERSION:S|b|beta|}-english-2.run

MAINTAINER=	avl@FreeBSD.org
COMMENT=	Serious Sam: The First Encounter

OPTIONS=	VORBIS	"Ogg playing support"	on

USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
NO_BUILD=	yes
NO_PACKAGE=	Distribution is 279MB; set FORCE_PACKAGE if you really want\
		to build this package
RESTRICTED=	Redistribution is limited, see license
PORTDOCS=	README.liflg ShellSymbols.txt changes.txt notes.txt
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if defined(WITH_VORBIS)
USE_LINUX_APPS+=libvorbis
PLIST_SUB+=	VORBIS=""
.else
PLIST_SUB+=	VORBIS="@comment "
.endif

# Gold Edition
.if exists(${CDROM_MOUNT}/Install/1_00c.gro)
GOLD=		yes
GRO_FILES=	ExtraTools music
PLIST_SUB+=	GOLD="" NORMAL="@comment "
.else
GRO_FILES=	ExtraTools a music scripts
PLIST_SUB+=	GOLD="@comment " NORMAL=""
.endif

do-extract:
	@${MKDIR} ${WRKSRC}/Data
	@cd ${WRKSRC} && ${SED} -e '1,/exit $$res/d' ${_DISTDIR}/${DISTFILES} |\
		${GUNZIP_CMD} -q | ${TAR} xf -
.for file in SeriousSamPatch105_USA_linux bins
	@${TAR} jx -C ${WRKSRC}/Data -f ${WRKSRC}/${file}.tar.bz2
.endfor

post-patch:
	@${REINPLACE_CMD} -e "s|^\(GAMEDIR=\).*|\1\"${DATADIR}\"|" \
		-e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/bin/${PORTNAME}

do-install:
.if !defined(CDROM_MOUNT)
	@${ECHO_CMD} "${PKGNAME} requires CDROM_MOUNT set to mount point of CD"
	@${FALSE}
.endif
.if !exists(${CDROM_MOUNT}/Install/Mods/SeriousSamTbn.tex)
	@${ECHO_CMD} "${PKGNAME} requires a retail First Encounter disc"
	@${FALSE}
.endif
	@${MKDIR} ${DATADIR}
.for gro in ${GRO_FILES}
	${INSTALL_DATA} "${CDROM_MOUNT}/Install/1_00_${gro}.gro" ${DATADIR}/1_00_${gro}.gro
.endfor
.if defined(GOLD)
.for gro in "" _scripts
	${INSTALL_DATA} "${CDROM_MOUNT}/Install/1_00c${gro}.gro" ${DATADIR}/1_00c${gro}.gro
.endfor
.endif
.for gro in 1_00_ExtraTools 1_04_patch
	${INSTALL_DATA} ${WRKSRC}/Data/${gro}.gro ${DATADIR}/${gro}.gro
.endfor
.for dir in Controls Data Levels Demos Mods Scripts VirtualTrees
	@cd ${CDROM_MOUNT}/Install && \
		${FIND} ${dir} -type d -exec \
			${MKDIR} "${DATADIR}/{}" \; && \
		${FIND} ${dir} -type f -exec \
			${INSTALL_DATA} "${CDROM_MOUNT}/Install/{}" "${DATADIR}/{}" \;
.endfor
.for dir in Controls Data Help Players SaveGame Scripts Temp
	@cd ${WRKSRC}/Data && \
		${FIND} ${dir} -type d -exec \
			${MKDIR} "${DATADIR}/{}" \; && \
		${FIND} ${dir} -type f -exec \
			${INSTALL_DATA} "${WRKSRC}/Data/{}" "${DATADIR}/{}" \;
.endfor
	@${MKDIR} ${DATADIR}/Bin
	@cd ${WRKSRC}/Data && \
		${FIND} Bin -type f -exec \
			${INSTALL_PROGRAM} "${WRKSRC}/Data/{}" "${DATADIR}/{}" \;
	${BRANDELF} -t Linux ${DATADIR}/Bin/ssam_*
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin
.if defined(WITH_VORBIS)
	${LN} -fs ${LINUXBASE}/usr/lib/libvorbisfile.so.3 ${DATADIR}/Bin/libvorbisfile.so
.endif
	@${FIND} -E ${DATADIR} -type f \
		-iregex ".*\.(ctl|txt|lst|ini|cfg|des|reg)" \
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
