# New ports collection makefile for:    linux_nwnclient
# Date created:         1 April 2003
# Whom:                 Erik Olson <erikolson@olsonexpress.com>
#
# $FreeBSD$
#

PORTNAME=	nwnclient
PORTVERSION=	1.65
PORTREVISION=	2
CATEGORIES=	games linux
MASTER_SITES=	http://content.bioware.com/neverwinternights/linux/${PORTVERSION:S/.//}/
PKGNAMEPREFIX=	linux-
DISTFILES=	nwclient129.tar.gz \
		linuxclientupdate1xxto${PORTVERSION:S/.//}eng.tar.gz

MAINTAINER=	des@FreeBSD.org
COMMENT=	Neverwinter Nights Linux (x86) Client

RUN_DEPENDS=	${LOCALBASE}/share/nwndata/NWNv129.txt:${PORTSDIR}/games/nwndata \
		${LINUXBASE}/usr/lib/libSDL-1.2.so.0:${PORTSDIR}/devel/linux-sdl12

.ifdef(WITH_NVIDIA_GL)
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
.else
RUN_DEPENDS+=	${LINUXBASE}/usr/X11R6/lib/libGL.so.1:${PORTSDIR}/graphics/linux_dri
.endif

NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
NWNDATADIR=	${LOCALBASE}/share/nwndata

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
	${FIND} ${DATADIR} -type d -print0 | ${XARGS} -0 chmod 0755
	${FIND} ${DATADIR} -type f -print0 | ${XARGS} -0 chmod 0644
	(cd ${DATADIR} && ${CHMOD} 0755 dmclient nwmain nwserver)
	${INSTALL_SCRIPT} ${WRKDIR}/nwn ${PREFIX}/bin/

.include <bsd.port.mk>
