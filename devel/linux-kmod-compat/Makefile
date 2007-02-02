# New ports collection makefile for: linux-bsd-kmod
# Date created:		1 February 2007
# Whom:			luigi
#
# $FreeBSD$

PORTNAME=	linux-kmod-compat
PORTVERSION=	20070202
CATEGORIES=	emulators linux multimedia
MASTER_SITES=	http://info.iet.unipi.it/~luigi/FreeBSD/
EXTRACT_SUFX=	.tgz

MAINTAINER=	luigi@FreeBSD.org
COMMENT=	Adaptation layer to build linux drivers on FreeBSD

WRKSRC=		${WRKDIR}/linux_compat

NO_PACKAGE=	The author does not want packages for this port.

# At the moment, emulation is only partial, but amd64 is coming
ONLY_FOR_ARCHS= i386

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 602100
BROKEN= Requires a recent USB stack. you have ${OSVERSION}
.endif

# Here is where install most things except the .mk file
MY_DST=	${DESTDIR}${PREFIX}/share/${PORTNAME}/linux_compat
MY_MK=	bsd.linux_kmod.mk

# Update the header location in the .mk
post-patch:
	@${REINPLACE_CMD} -e 's|^KLINPATH.*|KLINPATH?= ${MY_DST}|' \
		${WRKSRC}/${MY_MK}

do-build:	# nothing to build here, just a chance to update the source.

# Install bsd.linux_kmod.mk into /usr/share/mk so it can be found without
# extra arguments. All other files go into ${MY_DST}, with proper updating
# of owner and permissions. INSTALL is not recursive so we simulate it
# with cp -r/chmod/chown

do-install:
	${INSTALL_DATA} ${WRKSRC}/bsd.linux_kmod.mk /usr/share/mk
	${MKDIR} ${MY_DST}
	${CP} -Rp ${WRKSRC}/* ${MY_DST}
	${FIND}  ${MY_DST} -type f -exec ${CHMOD} ${SHAREMODE} \{\} \;
	# XXX TODO: fix modes on directories
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${MY_DST}

.include <bsd.port.post.mk>
