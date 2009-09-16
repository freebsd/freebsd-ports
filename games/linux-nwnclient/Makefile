# New ports collection makefile for:    linux_nwnclient
# Date created:         1 April 2003
# Whom:                 Erik Olson <erikolson@olsonexpress.com>
#
# $FreeBSD$
#

PORTNAME=	nwnclient
PORTVERSION=	1.68
CATEGORIES=	games linux
MASTER_SITES=	http://bioware.vo.llnwd.net/o1/neverwinternights/updates/linux/${PORTVERSION:S/.//}/ \
		http://nwdownloads.bioware.com/neverwinternights/linux/129/
PKGNAMEPREFIX=	linux-
DISTFILES=	nwclient129.tar.gz \
		English_linuxclient${PORTVERSION:S/.//}_orig.tar.gz

MAINTAINER=	sean-freebsd@farley.org
COMMENT=	Neverwinter Nights Linux (x86) Client

RUN_DEPENDS=	${LOCALBASE}/share/nwndata/NWNv129.txt:${PORTSDIR}/games/nwndata

NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_LINUX_APPS=	sdl12 xorglibs
NWNDATADIR=	${LOCALBASE}/share/nwndata

.ifdef WITH_NVIDIA_GL
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
USE_LINUX_APPS+=libglu
.else
USE_LINUX_APPS+=dri
.endif

PLIST_SUB+=	NWNVERSION="${PORTVERSION:S/.//}"

do-extract:
	${MKDIR} ${WRKSRC}
.for _distfile in ${DISTFILES}
	(cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/${_distfile} ${EXTRACT_AFTER_ARGS})
.endfor
	${RM} ${WRKSRC}/lib/libSDL* ${WRKSRC}/fixinstall ${WRKSRC}/nwn

do-configure:
	${SED} -e 's|%%NWNDATADIR%%|${NWNDATADIR}|' \
		-e 's|%%NWNCLIENTDIR%%|${DATADIR}|' \
		<${FILESDIR}/nwn.sh >${WRKDIR}/nwn

do-install:
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC} && ${FIND} . -print | \
	    ${CPIO} -pdmuv -R${SHAREOWN}:${SHAREGRP} ${DATADIR})
	${LN} -s ${LINUXBASE}/usr/lib/libstdc++-2-libc6.1-1-2.9.0.so \
		${DATADIR}/lib/libstdc++-libc6.1-2.so.3
	${FIND} ${DATADIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 0755
	${FIND} ${DATADIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 0644
	(cd ${DATADIR} && ${CHMOD} 0755 dmclient nwmain nwserver)
	${INSTALL_SCRIPT} ${WRKDIR}/nwn ${PREFIX}/bin/

.include <bsd.port.mk>
