# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	sof
PORTVERSION=	1.06a
CATEGORIES=	games linux
MASTER_SITES=	http://updates.lokigames.com/${PORTNAME}/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${PORTVERSION}-cdrom-x86
EXTRACT_SUFX=	.run

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Soldier of Fortune for Linux

PATCH_DEPENDS=	xdelta:${PORTSDIR}/misc/xdelta

USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
USE_LDCONFIG=	yes
NO_BUILD=	yes
NO_PACKAGE=	Distribution is 448MB; set FORCE_PACKAGE if you really want\
		to build this package
RESTRICTED=	Redistribution is limited, see license

XDELTA=		${LOCALBASE}/bin/xdelta patch
EXTRACT_FILES=	libopenal-0.0.so libSDL-1.1.so.0 README.105 README.106 base/pak2.pak
PORTDOCS=	README README.105 README.106
SUB_FILES=	pkg-message

.if !defined(CDROM_MOUNT)
IGNORE=		${PKGNAME} requires CDROM_MOUNT set to mount point of CD
.endif

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-extract:
	@${MKDIR} ${WRKSRC}/data ${WRKSRC}/patch
	@cd ${WRKSRC}/patch && ${SED} -e '1,/END_OF_STUB/d' ${_DISTDIR}/${DISTFILES} | \
		${GUNZIP_CMD} -q | ${TAR} xf -
.if !exists(${CDROM_MOUNT}/bin/x86/glibc-2.1/${PORTNAME})
	@${ECHO_CMD} "${PKGNAME} requires CD with Soldier of Fortune for Linux"
	@${FALSE}
.endif
	@${CP} ${CDROM_MOUNT}/bin/x86/glibc-2.1/${PORTNAME} ${CDROM_MOUNT}/kver.pub ${WRKSRC}/data
	@${CP} ${CDROM_MOUNT}/README ${WRKSRC}/data/
.for file in binaries paks
	@${TAR} x -C ${WRKSRC}/data -f ${CDROM_MOUNT}/${file}.tar.gz
.endfor
.for file in ${EXTRACT_FILES}
	@${GUNZIP_CMD} -qc ${WRKSRC}/patch/data/${file} > ${WRKSRC}/data/${file}
	@${RM} ${WRKSRC}/patch/data/${file}
.endfor

pre-patch:
	@cd ${WRKSRC}/patch/ && \
		${FIND} data -name "*.0" | \
		${SED} 's/\(.*\)\(.0\)/${XDELTA:S,/,\\/,g} & ${WRKSRC:S,/,\\/,g}\/\1 ${WRKSRC:S,/,\\/,g}\/\1.patched/' | ${SH}
	@cd ${WRKSRC} && \
		${FIND} data -name "*.patched" | \
		${SED} 's/\(.*\)\(.patched\)/${MV:S,/,\\/,g} & \1/' | ${SH}

post-patch:
	@${REINPLACE_CMD} -e "s|%%DATADIR%%|${DATADIR}|" ${WRKSRC}/data/${PORTNAME}

do-install:
	@${MKDIR} ${DATADIR}/base
	${INSTALL_PROGRAM} ${WRKSRC}/data/${PORTNAME} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/data/${PORTNAME}-bin ${DATADIR}
	@${BRANDELF} -t Linux ${DATADIR}/${PORTNAME}-bin
	${INSTALL_DATA} ${WRKSRC}/data/kver.pub ${DATADIR}
	cd ${WRKSRC}/data && \
		${FIND} . -name "*.so*" -exec ${INSTALL_PROGRAM} {} ${DATADIR}/{} \; && \
		${FIND} base -name "*.pak" -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/data/${i} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
