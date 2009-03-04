# New ports collection makefile for:	hso-kmod
# Date created:				12 May 2008
# Whom:					Ganael Laplanche <ganael.laplanche@martymac.com>
#
# $FreeBSD$
#

PORTNAME=	hso
PORTVERSION=	20081023
CATEGORIES=	comms kld
MASTER_SITES=	http://www.shapeshifter.se/pub/hso/
PKGNAMESUFFIX=	-kmod
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	Driver for Option HSDPA modem

NO_PACKAGE=	should be recompiled for a particular FreeBSD kernel

OPTIONS=	HSOCTL "Build hsoctl tool" on \
		DEVD "Install devd files" on \
		DEBUG "Build with debug symbols" on

SUB_FILES=	pkg-message
KMODDIR?=	/boot/modules
PLIST_SUB+=	KMODDIR=${KMODDIR}
MAKE_ENV+=	KMODDIR=${KMODDIR}

MAN4=	hso.4

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 800063
BROKEN=	Does not build with USB2
.endif

.if !defined(WITHOUT_HSOCTL)
HSOCTL_VERSION=	20081023
DISTFILES+=	hsoctl-${HSOCTL_VERSION}${EXTRACT_SUFX}
WRKSRC_HSOCTL=	${WRKDIR}/hsoctl-${HSOCTL_VERSION}
PLIST_SUB+=	PL_HSOCTL=""
MAN1=	hsoctl.1
.else
PLIST_SUB+=	PL_HSOCTL="@comment "
.endif
.if !defined(WITHOUT_DEVD)
PLIST_SUB+=	PL_DEVD=""
.else
PLIST_SUB+=	PL_DEVD="@comment "
.endif
.if defined(WITHOUT_DEBUG)
EXTRA_PATCHES+=	${PATCHDIR}/HSO-DEBUG-patch-Makefile
.endif

.if !exists(/usr/src/sys/Makefile)
IGNORE=	requires kernel source files
.elif ${OSVERSION} < 700055
IGNORE=	requires FreeBSD 7.0 or superior
.endif

post-patch:
.if !defined(WITHOUT_HSOCTL) && defined(WITHOUT_DEBUG)
	@${PATCH} -d ${WRKSRC_HSOCTL} < ${PATCHDIR}/HSOCTL-DEBUG-patch-Makefile
.endif

post-build:
.if !defined(WITHOUT_HSOCTL)
	@cd ${WRKSRC_HSOCTL} && ${SETENV} NO_MANCOMPRESS= ${MAKE} all
.endif

post-install:
	${INSTALL_MAN} ${MAN4:S|^|${WRKSRC}/|} ${PREFIX}/man/man4
.if !defined(WITHOUT_HSOCTL)
	@cd ${WRKSRC_HSOCTL} && \
		${SETENV} DESTDIR=${PREFIX}/ BINDIR=bin MANDIR=man/man NO_MANCOMPRESS= \
		${MAKE} install
.endif
.if !defined(WITHOUT_DEVD)
	${MKDIR} ${PREFIX}/etc/devd
	${INSTALL_DATA} ${FILESDIR}/option-icon.conf.sample ${PREFIX}/etc/devd/
	@if [ ! -f ${PREFIX}/etc/devd/option-icon.conf ]; then \
		${CP} -p ${PREFIX}/etc/devd/option-icon.conf.sample ${PREFIX}/etc/devd/option-icon.conf; \
	fi
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
