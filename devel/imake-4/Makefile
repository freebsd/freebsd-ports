# New ports collection makefile for:    Imake
# Date created:         01 Mar 2000
# Whom:                 max
#
# $FreeBSD$
#

PORTNAME=	imake
PORTVERSION=	4.1.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	4.1.0
DISTFILES=	X410src-1.tgz

MAINTAINER=	taguchi@tohoku.iij.ad.jp

PREFIX?=	${X11BASE}
DIST_SUBDIR=	xc
WRKSRC=		${WRKDIR}/xc/config
MTREE_FILE=	/etc/mtree/BSD.x11-4.dist
PATCH_DIST_ARGS=	--force -d ${WRKDIR} --forward --quiet -E ${PATCH_DIST_STRIP} 2>/dev/null || true
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - xc/Imakefile \
			xc/Makefile \
			xc/config \
			xc/include \
			xc/extras \
			xc/programs/Xserver/hw/xfree86/xf86Version.h
MAN1=		imake.1 \
		lndir.1 \
		makedepend.1 \
		makeg.1 \
		makestrs.1 \
		mkdirhier.1 \
		pswrap.1 \
		revpath.1 \
		rman.1 \
		xmkmf.1
MANCOMPRESSED=	yes
SCRIPTS_ENV+=	OSVERSION=${OSVERSION} \
		HasSecureRPC=${HasSecureRPC} \
		HasXdmAuth=${HasXdmAuth} \
		HasPam=${HasPam} \
		BuildPexExt=${BuildPexExt} \
		BuildXinerama=${BuildXinerama} \
		BuildXIE=${BuildXIE} \
		BuildAoutLibraries=${BuildAoutLibraries} \
		ForceNormalLib=${ForceNormalLib} \
		DebuggableLibraries=${DebuggableLibraries} \
		JoystickSupport=${JoystickSupport} \
		InstallXdmConfig=${InstallXdmConfig} \
		InstallXinitConfig=${InstallXinitConfig} \
		InstallAppDefFiles=${InstallAppDefFiles} \
		ExtendedInputDevices=${ExtendedInputDevices} \
		Build75DpiFonts=${Build75DpiFonts}  \
		Build100DpiFonts=${Build100DpiFonts} \
		BuildSpeedoFonts=${BuildSpeedoFonts} \
		BuildType1Fonts=${BuildType1Fonts} \
		BuildCIDFonts=${BuildCIDFonts} \
		BuildTTFonts=${BuildTTFonts}
INSTALL_TARGET=	install install.man
LATEST_LINK=	imake-4
# ---
# User Config:
# All variables are same as Imake config macros.
# For more details, see ${WRKDIR}/xc/config/cf/README.
# Followings will write to ${PFEFIX}/lib/X11/config/xf86site.def,
# and all of XFree86-4-* ports will use them as default value.
# Offcause, you can override them (at your own risk ;-).
# Read scripts/configure for more details.
# ---
HasSecureRPC?=		YES
HasXdmAuth?=		YES
HasPam?=		YES
BuildPexExt?=		YES
BuildXinerama?=		YES
BuildXIE?=		YES
BuildAoutLibraries?=	NO
ForceNormalLib?=	YES
DebuggableLibraries?=	NO
JoystickSupport?=	YES
InstallXdmConfig?=	YES
InstallXinitConfig?=	YES
InstallAppDefFiles?=	YES
Build75DpiFonts?=	YES
Build100DpiFonts?=	YES
BuildSpeedoFonts?=	YES
BuildType1Fonts?=	YES
BuildCIDFonts?=		YES
BuildTTFonts?=		YES
# ---
# Undocumented variables:
# ExtendedInputDevices: if you want to support some extended input device,
#                       such as wacom tablets, set YES.
#                       if NO, only mouse device will be supported.
ExtendedInputDevices?=	YES
# ---
# Unconfigurable variables:
# BuildXF86Setup=NO   : XF86Setup is now broken ;-(
#
# BuildFontServer     : if you want to use xfs, then do not install its ports.
# BuildFonts          : if you don't need fonts, then do not install its ports.
# BuildCyrillicFonts  : install ${PORTSDIR}/x11-fonts/XFree86-4-fontCyrillic
# BuildLatin2Fonts    : install ${PORTSDIR}/x11-fonts/XFree86-4-fontLatin2
#             [Note1] all of loadable modules (such as speedo, type1)
#                      will be compiled/installed as default.
#             [Note2] default/traditional X11 fonts are corrected under
#                     ${PORTSDIR}/x11-fonts/XFree86-4-fontDefaultBitmaps.
#
# XF86CardDrivers     : XFree86-4-* ports try to support many devices.
# XInputDrivers       : So if you want to config them, edit manualy.
#
# NothingOutsideProjectRoot=YES : any ports will not install to /etc/ dir.
#             This means config files will be installed to ${PREFIX}/lib/X11.
#             It's a traditional place ;-)
# InstallXserverSetUID=NO : use Xwrapper.
# End of XFree86 configrations

.if ${HasXdmAuth} == YES
.if defined(USA_RESIDENT) && ${USA_RESIDENT} == YES
.if !exists(${DISTDIR}/${DIST_SUBDIR}/Wraphelp.c)
pre-everything::
	@${ECHO_MSG} "You don't have Wraphelp.c: HasXdmAuth disabled."
HasXdmAuth=	NO
.else
pre-everything::
	@${ECHO_MSG} "Assuming that you have fetched a USA-Legal Wraphelp.c."
.endif	# ! having Wraphelp.c
.else
MASTER_SITES+=	ftp://psych.psy.uq.oz.au/pub/X11R5/ \
		ftp://ftp.internat.freebsd.org/pub/FreeBSD/X11-Crypto/ \
		ftp://ftp3.za.freebsd.org/pub/FreeBSD/X11-Crypto/
EXTRACT_ONLY=	X410src-1.tgz
DISTFILES+=	Wraphelp.c
IGNOREFILES=	Wraphelp.c
.endif	# USA_RESIDENT
.endif	# HasXdmAuth

.include <bsd.port.mk>
