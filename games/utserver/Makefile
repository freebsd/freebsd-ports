# New ports collection makefile for:	Unreal Tournament Dedicated Server
# Date created:				Thu Oct 4 23:38:00 CEST 2001
# Whom:			Martin Matuska <martin@tradex.sk> et al
#
# $FreeBSD$
#

PORTNAME=	utserver
PORTVERSION=	451
PORTREVISION=	1
CATEGORIES=	games linux
MASTER_SITES=   http://public.planetmirror.com/pub/lokigames/installers/ut/:p436 \
		http://fileserver.talkware.net/ut/:p436 \
		http://freebsd.unixfreunde.de/sources/:p436 \
		http://www.utpg.org/patches/:p451
DISTFILES=      ut-server-436.tar.gz:p436 ${PATCH451FILES}
EXTRACT_ONLY=   ut-server-436.tar.gz

MAINTAINER=	ports@logvinov.com
COMMENT=	Unreal Tournament Dedicated Server for Linux

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libSDL-1.2.so.0:${PORTSDIR}/devel/linux-sdl12
BUILD_DEPENDS=	${RUN_DEPENDS}

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_PERL5=	yes
NO_CDROM=	Size; the data set is much too big
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/ut-server
USE_RC_SUBR=    ucc

UTDIR=          ut-server
PLIST_SUB=      UTDIR="${UTDIR}/"
SUB_LIST=       UTDIR="${PREFIX}/${UTDIR}"
SUB_FILES=      pkg-message
PATCH451FILES=  UTPGPatch451.tar.bz2:p451
EXTRA_PATCHES=  ${WRKDIR}/patch-ngstatsut

pre-patch:
	@${SED} -e "s!%%LOCALBASE%%!${LOCALBASE}!" \
	    -e "s!%%UTDIR%%!${PREFIX}/${UTDIR}!" \
	    ${FILESDIR}/template-patch-ngstatsut > \
	    ${WRKDIR}/patch-ngstatsut

do-patch:
	@${TAR} jx -C ${WRKSRC} -X ${FILESDIR}/excludefiles \
	   -f ${_DISTDIR}/${PATCH451FILES:C/:.*//}
# remove trailing ^M
	@${FIND} -E ${WRKSRC} -type f \
		-iregex ".*\.(bat|cfg|gam|htm|html|inf|ini|int|lst|pl|pm|sc|sh|scr|txt|url|uhtm|inc)" \
		-exec ${PERL} -pi -ne 's!\r\n!\n!' {} 1>/dev/null 2>&1 \;

do-install:
	@${CP} -Rp ${WRKSRC}/ ${PREFIX}/${UTDIR}
	@${RM} -f ${PREFIX}/${UTDIR}/System/libSDL-1.1.so.0

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
