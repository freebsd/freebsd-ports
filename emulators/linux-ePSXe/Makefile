# New ports collection makefile for:	linux-ePSXe
# Date created:			21 Dec 2002
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	ePSXe
PORTVERSION=	1.5.2
CATEGORIES=	emulators linux
MASTER_SITES=	http://download.epsxe.com/files/
PKGNAMEPREFIX=	linux-
DISTNAME=	epsxe152lin

MAINTAINER=	jylefort@brutele.be

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk

USE_ZIP=	yes
NO_WRKSUBDIR=	yes

ONLY_FOR_ARCHS=	i386

# Linux binary should not be stripped by INSTALL_PROGRAM
# because as a side effect it brands the binary as FreeBSD.
STRIP=

.include <bsd.port.pre.mk>

EPSXE=		${PREFIX}/libexec/linux-epsxe

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
SHAREDIR=	${PREFIX}/share/${PKGNAMEPREFIX}${PORTNAME}

PSEMUPRO_PLUGINS_DIR=	${LOCALBASE}/lib/linux-psemupro/plugins
PSEMUPRO_CFGBINS_DIR=	${LOCALBASE}/libexec/linux-psemupro/cfg
PSEMUPRO_CFGFILES_DIR=	${LOCALBASE}/share/linux-psemupro/cfg

do-build:
	${MKDIR} ${WRKSRC}/FreeBSD
	${SED} \
		-e "s,@EPSXE@,${EPSXE},g" \
		-e "s,@SHAREDIR@,${SHAREDIR},g" \
		-e "s,@PSEMUPRO_PLUGINS_DIR@,${PSEMUPRO_PLUGINS_DIR},g" \
		-e "s,@PSEMUPRO_CFGBINS_DIR@,${PSEMUPRO_CFGBINS_DIR},g" \
		-e "s,@PSEMUPRO_CFGFILES_DIR@,${PSEMUPRO_CFGFILES_DIR},g" \
		${FILESDIR}/linux-epsxe_install.in \
		>${WRKSRC}/FreeBSD/linux-epsxe_install

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} \
		${FILESDIR}/linux-epsxe \
		${WRKSRC}/FreeBSD/linux-epsxe_install \
		${PREFIX}/bin

	${MKDIR} ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/epsxe ${EPSXE}

	${MKDIR} ${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/keycodes.lst ${SHAREDIR}

	${MKDIR} ${SHAREDIR}/cheats
	${INSTALL_DATA} \
		${WRKSRC}/cheats/breath_of_fire_4_usa.cht \
		${WRKSRC}/cheats/chrono_cross_ntsc.cht \
		${WRKSRC}/cheats/tarzan_pal.cht \
		${SHAREDIR}/cheats

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
