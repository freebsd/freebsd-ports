# New ports collection makefile for:	linux-ePSXe
# Date created:			21 Dec 2002
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	epsxe
PORTVERSION=	1.6.0
CATEGORIES=	emulators linux
MASTER_SITES=	http://www.epsxe.com/files/
PKGNAMEPREFIX=	linux-
DISTNAME=	epsxe160lin

MAINTAINER=	jylefort@brutele.be
COMMENT=	A Sony Playstation emulator (Linux version)

# The binary is built against glibc 2.3, so we need linux_base-8.
RUN_DEPENDS=	${LINUXBASE}/lib/libc-2.3.2.so:${PORTSDIR}/emulators/linux_base-8 \
		${LINUXBASE}/usr/X11R6/lib/libX11.so.6:${PORTSDIR}/x11/linux-XFree86-libs \
		${LINUXBASE}/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk

USE_X_PREFIX=	yes
USE_ZIP=	yes
NO_WRKSUBDIR=	yes

ONLY_FOR_ARCHS=	i386

# Linux binary should not be stripped by INSTALL_PROGRAM
# because as a side effect it brands the binary as FreeBSD.
STRIP=

.include <bsd.port.pre.mk>

EPSXE=		${PREFIX}/libexec/epsxe

PSEMUPRO_PLUGINS_DIR=	${LOCALBASE}/lib/psemupro/plugins
PSEMUPRO_CFGBINS_DIR=	${LOCALBASE}/libexec/psemupro/cfg
PSEMUPRO_CFGFILES_DIR=	${LOCALBASE}/share/psemupro/cfg

do-build:
	${MKDIR} ${WRKSRC}/FreeBSD
	${SED} \
		-e "s,@EPSXE@,${EPSXE},g" \
		-e "s,@DATADIR@,${DATADIR},g" \
		-e "s,@PSEMUPRO_PLUGINS_DIR@,${PSEMUPRO_PLUGINS_DIR},g" \
		-e "s,@PSEMUPRO_CFGBINS_DIR@,${PSEMUPRO_CFGBINS_DIR},g" \
		-e "s,@PSEMUPRO_CFGFILES_DIR@,${PSEMUPRO_CFGFILES_DIR},g" \
		${FILESDIR}/epsxe-install.in \
		>${WRKSRC}/FreeBSD/epsxe-install

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} \
		${FILESDIR}/epsxe \
		${WRKSRC}/FreeBSD/epsxe-install \
		${PREFIX}/bin

	${MKDIR} ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/epsxe ${EPSXE}

	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/keycodes.lst ${DATADIR}

	${MKDIR} ${DATADIR}/cheats
	${INSTALL_DATA} \
		${WRKSRC}/cheats/breath_of_fire_4_usa.cht \
		${WRKSRC}/cheats/chrono_cross_ntsc.cht \
		${WRKSRC}/cheats/tarzan_pal.cht \
		${DATADIR}/cheats

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} \
		${WRKSRC}/docs/epsxe_en.txt \
		${WRKSRC}/docs/epsxe_linux_en.txt \
		${WRKSRC}/docs/epsxe_linux_sp.txt \
		${WRKSRC}/docs/epsxe_sp.txt \
		${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
