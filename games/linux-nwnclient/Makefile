# New ports collection makefile for:    linux_nwnclient
# Date created:         1 April 2003
# Whom:                 Erik Olson <erikolson@olsonexpress.com>
#
# $FreeBSD$
#

PORTNAME=	nwnclient
PKGNAMEPREFIX=	linux-
PORTVERSION=	1.62
CATEGORIES=	games linux
MASTER_SITES=	http://nwdownloads.bioware.com/neverwinternights/linux/${PORTVERSION:S/.//}/ \
		http://nwdownloads.bioware.com/neverwinternights/linux/129/
DISTFILES=	nwclient129.tar.gz \
		linuxclientupdate129to${PORTVERSION:S/.//}eng.tar.gz

MAINTAINER=	des@FreeBSD.org
COMMENT=	Neverwinter Nights Linux (x86) Client

RUN_DEPENDS=	${LOCALBASE}/share/nwndata/NWNv129.txt:${PORTSDIR}/games/nwndata \
		/compat/linux/usr/X11R6/lib/libGL.so.1.2:${PORTSDIR}/graphics/linux_dri \
		/compat/linux/usr/lib/libSDL-1.2.so.0:${PORTSDIR}/devel/linux-sdl12

USE_LINUX=	yes
NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386
NWNDATADIR=	${LOCALBASE}/share/nwndata

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
	${INSTALL_PROGRAM} ${WRKDIR}/nwn ${PREFIX}/bin/

.include <bsd.port.mk>
