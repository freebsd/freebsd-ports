# New ports collection makefile for:	xmess
# Date created:				Tue Aug 17 00:21:10 MET DST 1999
# Whom:					nox@jelal.kn-bremen.de
#
# $FreeBSD$
#

PORTNAME=	xmess
PORTVERSION=	0.2b4.1
CATEGORIES=	emulators
MASTER_SITES=	http://mess.emuverse.com/files/ \
		http://www.vintagegaming.com/hosted/vectrex/
DISTNAME=	unix02s4
DISTFILES=	${DISTNAME}.tgz pdp1.zip

#MAINTAINER=	mycroft@NetBSD.ORG	# NetBSD
MAINTAINER=	nox@jelal.kn-bremen.de

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

EXTRACT_ONLY=	${DISTNAME}.tgz

USE_X_PREFIX=	yes
USE_GMAKE=	yes
MAKE_ENV+=	OPSYS=${OPSYS} ARCH=${ARCH} MACHINE_ARCH=${ARCH} \
		DESTDIR=${DESTDIR} \
		INSTALL_MAN="${INSTALL_MAN}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		NETBSD_JOYSTICK="${NETBSD_JOYSTICK}" \
		DISPLAY_METHOD="${DISPLAY_METHOD}"
MAKEFILE=	makefile.unix
DISPLAY_METHOD=	x11
ALL_TARGET=	xmess.${DISPLAY_METHOD}

WRKSRC=		${WRKDIR}/xmess-0.2b4.1

MESSDIR=	${PREFIX}/share/xmess
MESSLIB=	${PREFIX}/lib/xmess
.if exists(/usr/include/machine/joystick.h)
NETBSD_JOYSTICK=yes
.else
NETBSD_JOYSTICK=no
.endif

post-patch:
	(cd ${WRKSRC}/doc && ${SED} 's|@MESSDIR@|${MESSDIR}|;s|@MESSLIB@|${MESSLIB}|' xmessrc.dist >xmessrc)

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${ALL_TARGET} ${PREFIX}/bin/xmess)
	${MKDIR} ${MESSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} xmessrc ${MESSDIR}/xmessrc)
	${MKDIR} ${MESSLIB}
	${INSTALL_DATA} ${_DISTDIR}/pdp1.zip ${MESSLIB}/spacewar.zip
	@${ECHO} try \`xmess pdp1 spacewar\' for the original 1961 Space Wars

.include <bsd.port.mk>
