# New ports collection makefile for:	bfe
# Date created:		02 February 2000
# Whom:			jhb
#
# $FreeBSD$
#

PORTNAME=	bfe2
PORTVERSION=	20030124
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	bfe
DISTNAME=	bfe2-24jan2003

MAINTAINER=	greid@FreeBSD.org
COMMENT=	X11 GUI for the bochs debugger (revision 2)

RUN_DEPENDS=	bochs:${PORTSDIR}/emulators/bochs

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk12
CONFIGURE_SCRIPT=	configure.sh
WRKSRC=		${WRKDIR}/bfe2

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|%%CC%%|${CC}|' -e 's|%%CFLAGS%%|${CFLAGS}|' \
		-e 's|gtk-config|${GTK_CONFIG}|' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

do-configure:
	@cd ${WRKSRC} && ${SH} ${CONFIGURE_SCRIPT}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bfe2 ${PREFIX}/bin
	-@${MKDIR} ${PREFIX}/share/bfe
	${INSTALL_DATA} ${WRKSRC}/README.bferc ${PREFIX}/share/bfe/bferc.sample
	${INSTALL_DATA} ${WRKSRC}/README.bferc ${PREFIX}/share/bfe

.include <bsd.port.mk>
