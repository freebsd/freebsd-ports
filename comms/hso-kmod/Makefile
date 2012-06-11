# New ports collection makefile for:	hso-kmod
# Date created:				12 May 2008
# Whom:					Ganael Laplanche <ganael.laplanche@martymac.org>
#
# $FreeBSD$
#

PORTNAME=	hso
PORTVERSION=	20081023
PORTREVISION=	2
CATEGORIES=	comms kld
MASTER_SITES=	http://www.shapeshifter.se/pub/hso/
PKGNAMESUFFIX=	-kmod
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Driver for Option HSDPA modem

LICENSE=	BSD

CONFLICTS=	uhso-kmod-[0-9]*

NO_PACKAGE=	should be recompiled for a particular FreeBSD kernel

OPTIONS_DEFINE=	HSOCTL DEVD DEBUG
OPTIONS_DEFAULT=	HSOCTL DEVD

HSOCTL_DESC=	Build hsoctl tool

SUB_FILES=	pkg-message
KMODDIR?=	/boot/modules
PLIST_SUB+=	KMODDIR=${KMODDIR}
MAKE_ENV+=	KMODDIR=${KMODDIR}

MAN4=	hso.4

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 800063
BROKEN=	does not build with USB2, please try comms/uhso-kmod instead
.endif

.if ${PORT_OPTIONS:MHSOCTL}
HSOCTL_VERSION=	20081023
DISTFILES+=	hsoctl-${HSOCTL_VERSION}${EXTRACT_SUFX}
WRKSRC_HSOCTL=	${WRKDIR}/hsoctl-${HSOCTL_VERSION}
PLIST_SUB+=	PL_HSOCTL=""
MAN1=	hsoctl.1
.else
PLIST_SUB+=	PL_HSOCTL="@comment "
.endif
.if ${PORT_OPTIONS:MDEVD}
PLIST_SUB+=	PL_DEVD=""
.else
PLIST_SUB+=	PL_DEVD="@comment "
.endif
.if empty(${PORT_OPTIONS:MDEBUG})
EXTRA_PATCHES+=	${PATCHDIR}/HSO-NODEBUG-patch-Makefile
.endif

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=	requires kernel source files
.elif ${OSVERSION} < 700055
IGNORE=	requires FreeBSD 7.0 or superior
.endif

post-patch:
.if !empty(${PORT_OPTIONS:MHSOCTL}) && empty(${PORT_OPTIONS:MDEBUG})
	@${PATCH} -d ${WRKSRC_HSOCTL} < ${PATCHDIR}/HSOCTL-NODEBUG-patch-Makefile
.endif

post-build:
.if ${PORT_OPTIONS:MHSOCTL}
	@cd ${WRKSRC_HSOCTL} && ${SETENV} NO_MANCOMPRESS= ${MAKE} all
.endif

post-install:
	${INSTALL_MAN} ${MAN4:S|^|${WRKSRC}/|} ${PREFIX}/man/man4
.if ${PORT_OPTIONS:MHSOCTL}
	@cd ${WRKSRC_HSOCTL} && \
		${SETENV} DESTDIR=${PREFIX}/ BINDIR=bin MANDIR=man/man NO_MANCOMPRESS= \
		${MAKE} install
.endif
.if ${PORT_OPTIONS:MDEVD}
	${MKDIR} ${PREFIX}/etc/devd
	${INSTALL_DATA} ${FILESDIR}/option-icon.conf.sample ${PREFIX}/etc/devd/
	@if [ ! -f ${PREFIX}/etc/devd/option-icon.conf ]; then \
		${CP} -p ${PREFIX}/etc/devd/option-icon.conf.sample ${PREFIX}/etc/devd/option-icon.conf; \
	fi
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
