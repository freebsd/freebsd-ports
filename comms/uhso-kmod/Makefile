# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	uhso
PORTVERSION=	20100416
PORTREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	http://www.shapeshifter.se/pub/hso/
PKGNAMESUFFIX=	-kmod
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Driver for Option HSDPA modem (USB2 version)

LICENSE=	BSD

CONFLICTS=	hso-kmod-[0-9]*

DEPRECATED=	included in base system on all supported releases
EXPIRATION_DATE=2013-12-01

NO_PACKAGE=	should be recompiled for a particular FreeBSD kernel

OPTIONS_DEFINE=	UHSOCTL DEBUG
OPTIONS_DEFAULT=	UHSOCTL

UHSOCTL_DESC=	Build uhsoctl tool

SUB_FILES=	pkg-message

MAN4=		uhso.4

NO_STAGE=	yes

USES=		kmod
.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 800063
IGNORE=		requires FreeBSD 8.0 or later, please try comms/hso-kmod instead
.elif ${OSVERSION} >= 800501
IGNORE=	the uhso driver is already available in the base system
.endif

.if ${PORT_OPTIONS:MUHSOCTL}
UHSOCTL_VERSION=	20100416
DISTFILES+=	uhsoctl-${UHSOCTL_VERSION}${EXTRACT_SUFX}
WRKSRC_UHSOCTL=	${WRKDIR}/uhsoctl-${UHSOCTL_VERSION}
PLIST_SUB+=	PL_UHSOCTL=""
MAN1=	uhsoctl.1
.else
PLIST_SUB+=	PL_UHSOCTL="@comment "
.endif

.if empty(PORT_OPTIONS:MDEBUG)
EXTRA_PATCHES+=	${PATCHDIR}/UHSO-NODEBUG-patch-Makefile
.endif

post-patch:
.if !empty(PORT_OPTIONS:MUHSOCTL) && !empty(PORT_OPTIONS:MDEBUG)
	@${PATCH} -d ${WRKSRC_UHSOCTL} < ${PATCHDIR}/UHSOCTL-DEBUG-patch-Makefile
.endif

post-build:
.if ${PORT_OPTIONS:MUHSOCTL}
	@cd ${WRKSRC_UHSOCTL} && ${SETENV} NO_MANCOMPRESS= ${MAKE} all
.endif

post-install:
	${INSTALL_MAN} ${MAN4:S|^|${WRKSRC}/|} ${PREFIX}/man/man4
.if ${PORT_OPTIONS:MUHSOCTL}
	@cd ${WRKSRC_UHSOCTL} && \
		${SETENV} DESTDIR=${PREFIX}/ BINDIR=bin MANDIR=man/man NO_MANCOMPRESS= \
		${MAKE} install
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
