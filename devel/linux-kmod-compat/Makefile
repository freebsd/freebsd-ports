# New ports collection makefile for: linux-bsd-kmod
# Date created:		1 February 2007
# Whom:			luigi
#
# $FreeBSD$

PORTNAME=	linux-kmod-compat
PORTVERSION=	20080408
CATEGORIES=	devel emulators linux multimedia
MASTER_SITES=	http://info.iet.unipi.it/~luigi/FreeBSD/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Adaptation layer to build Linux drivers on FreeBSD

WRKSRC=		${WRKDIR}/linux_compat
NO_BUILD=	yes

# Here is where install most things except the .mk file
MY_DST=	${DATADIR}/linux_compat
MY_MK=	bsd.linux_kmod.mk

PLIST=	${WRKDIR}/pkg-plist

post-extract:
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s|${WRKSRC}|%%DATADIR%%/linux_compat|" >${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s|${WRKSRC}|@dirrm %%DATADIR%%/linux_compat|" >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%" >> ${PLIST}
	@${ECHO_CMD} "@cwd /usr/share/mk" >> ${PLIST}
	@${ECHO_CMD} "bsd.linux_kmod.mk" >> ${PLIST}

# Update the header location in the .mk
post-patch:
	@${REINPLACE_CMD} -i '' -e 's|^KLINPATH.*|KLINPATH?= ${MY_DST}|' \
		${WRKSRC}/${MY_MK}

# Install bsd.linux_kmod.mk into /usr/share/mk so it can be found without
# extra arguments.

do-install:
	${INSTALL_DATA} ${WRKSRC}/bsd.linux_kmod.mk /usr/share/mk
	@${MKDIR} ${MY_DST}
	@${CP} -Rp ${WRKSRC}/* ${MY_DST}
	@${FIND} ${MY_DST} -type f -exec ${CHMOD} ${SHAREMODE} \{\} \;
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${MY_DST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
