# New ports collection makefile for:	GLX
# Version required:     CVS
# Date created:         13 September 1999
# Whom:                 Marc E E van Woerkom  <van.woerkom@netcologne.de>
#
# $FreeBSD$
#
#
# Notes:
#
#  . You need at least XFree86 3.3.4 (or the glx patched 3.3.3.1)!
#    This port is set up for 3.3.5
#
#  . Mesa-3.0 has to be uninstalled before this port builds!
#    Why? Because we need to create a glx aware version.
#
#  . This stuff has been tested with
#    - a Diamond Viper 330 (RIVA 128),
#    - a Diamond Viper 550 (RIVA TNT),
#    - and was reported to work with a Matrox G200 card
#
#  . Glx on n-vidia's site is outdated (we have XFree86-3.3.5 now
#    so I rolled my own snapshot of the open project glx code.
#    It is slightly outdated but will be updated soon.
#
#  . The current Mesa3 port for FreeBSD does not stop at the 'patch'
#    target, but will instead try to build X11 immediatley if XFree86
#    is not present.
#    For this version (XFree86 3.3.5 needs no patches for glx yet) we
#    ignore this wrong behaviour.
#
#  . We need tclsh for building - the choice for tclsh 8.0 is due to
#    lack of time to include a proper selection scheme
#
#  . You can set CHIPSET_3D appropriately in /etc/make.conf if the
#    question bugs you
#

PORTNAME=	glx
PORTVERSION=	990802
CATEGORIES=	graphics
MASTER_SITES=	http://people.FreeBSD.org/~3d/distfiles/glx/XF3.3.5/
DISTFILES=	${DISTNAME}.tar.bz2 \
	 	riva-x-glx.faq.bz2 \
		Mesa-3_0.diff.bz2

MAINTAINER=	3d@freebsd.org

# search for tclsh, if not present build it
BUILD_DEPENDS=	tclsh8.0:${PORTSDIR}/lang/tcl80

# These settings are here to make future updates to this port easier
#PATCH_XFREE=	yes
PATCH_MESA=	yes

.if defined(PATCH_XFREE)
BUILD_DEPENDS= 	/nonexistent:${PORTSDIR}/x11/XFree86:patch
.endif
.if defined(PATCH_MESA)
BUILD_DEPENDS= 	/nonexistent:${PORTSDIR}/graphics/Mesa3:patch
.endif

USE_BZIP2=	yes

EXTRACT_ONLY=	${DISTNAME}.tar.bz2

DIST_SUBDIR=	glx

WRKSRC=		${WRKDIR}/${DISTNAME}

# I don't want to build XFree86 too soon, so don't use USE_X_PREFIX
#USE_X_PREFIX=	yes
PREFIX=		${X11BASE}

XFCONFIG=	/etc/XF86Config

XFREEVER=	3.3.5
XFREEDIR=	${PORTSDIR}/x11/XFree86/work/xc

MESAVER=	3.0
MESADIR=	${PORTSDIR}/graphics/Mesa3/work/Mesa-3.0

# As we ask for CHIPSET_3D if not set
IS_INTERACTIVE=	YES

# comment out the following line,
# if you want to build with Imake (Linux/alpha favours that)
USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes

# we support nvidia RIVA 128, TNT.. and Matrox G200/400 cards
.if defined(CHIPSET_3D)
.if ${CHIPSET_3D} == RIVA
WITH_CHIPSET=	--with-chipset=tnt
.endif
.if ${CHIPSET_3D} == MGA
WITH_CHIPSET=	--with-chipset=mga
.endif
.endif

CONFIGURE_ARGS= --with-mesa=${MESADIR} \
		--with-mesa-version=mesa30 \
		${WITH_CHIPSET}  # --with-mmx-asm --with-3dnow-asm

USE_GMAKE=	yes

.if !defined(GNU_CONFIGURE)
USE_IMAKE= 	yes
.endif

.include <bsd.port.pre.mk>

#
#  before 'patch'
#
#  . apply some patches to the Mesa 3.0 distribution
#
pre-patch:
.if defined(PATCH_XFREE)
	@${ECHO} "=> Patching XFree86-${XFREEVER} for GLX .."
	cd ${XFREEDIR}; \
	${PATCH} -s -f <${FILESDIR}/XFree86-3_3_5.diff
.endif
.if defined(PATCH_MESA)
	@${ECHO} "=> Checking Mesa-${MESAVER} installation .."
	@if \
	  pkg_info -e "Mesa-${MESAVER}"; \
	then \
	  ${ECHO} "Found Mesa-${MESAVER} - please deinstall"; \
	  ${ECHO} "Aborting.."; \
	  ${FALSE} ; \
	fi
.if exists(${MESADIR}/../.glxpatch_done)
	@${ECHO} "=> Mesa-${MESAVER} seems already patched for GLX .."
.else
	@${ECHO} "=> Patching Mesa-${MESAVER} for GLX acceleration .."
	@${ECHO} "(ignore the rejections, as they should happen in comments only)"
	-cd ${MESADIR}; \
	bzcat ${DISTDIR}/${DIST_SUBDIR}/Mesa-3_0.diff.bz2 | ${PATCH} -s -f
	${TOUCH} ${MESADIR}/../.glxpatch_done
.endif
.endif

#
#  before 'configure'
#
#  . patch glx configure.in, libGL/Makefile.in,
#    serverglx/Makefile.in (yes, this is an ugly hack)
#
pre-configure:
.if !defined(CHIPSET_3D) || ${CHIPSET_3D} != RIVA && ${CHIPSET_3D} != MGA
	@${ECHO}
	@${ECHO} You must set the variable CHIPSET_3D to 'RIVA' if you use
	@${ECHO} a nvidia RIVA 128, 128ZX, TNT, TNT2 .. based graphics card,
	@${ECHO} or to 'MGA' if you use a Matrox G200/G400 graphics adapter
	@${FALSE}
.endif
.if defined(GNU_CONFIGURE)
	@${ECHO} "=> Adjusting ${WRKSRC}/configure.in .."
	@cd ${WRKSRC}; \
	${SED} -e 's;tclsh;tclsh8\.0;g' \
	<configure.in >configure.in.new; \
	${MV} configure.in.new configure.in
	@${ECHO} "=> Adjusting ${WRKSRC}/libGL/Makefile.in .."
	@cd ${WRKSRC}/libGL; \
	${SED} -e 's;SOGLREV = 1\.0;SOGLREV = 1;' \
	<Makefile.in >Makefile.in.new; \
	${MV} Makefile.in.new Makefile.in
	@${ECHO} "=> Adjusting ${WRKSRC}/servGL/serverglx/Makefile.in .."
	@cd ${WRKSRC}/servGL/serverglx; \
	${SED} -e 's;tclsh;tclsh8\.0;g' \
	<Makefile.in >Makefile.in.new; \
	${MV} Makefile.in.new Makefile.in
.endif

#
#  after 'configure'
#
#  . only for the old IMAKE style configuration
#
post-configure:
.if !defined(GNU_CONFIGURE)
	@${ECHO} "Using IMAKE"
	@${ECHO} "=> Adjusting ${WRKSRC}/Config .."
	@cd ${WRKSRC}; \
	${SED} -e 's;XSERVTOP = .*;XSERVTOP = ${XFREEDIR};' \
	       -e 's;MESATOP = .*;MESATOP = ${MESADIR};' \
	<Config.in >Config;
	@${ECHO} "=> Adjusting ${WRKSRC}/libGL/Imakefile .."
	@cd ${WRKSRC}/libGL; \
	${SED} -e 's;tclsh;tclsh8\.0;' <Imakefile >Imakefile.new; \
	${MV} Imakefile.new Imakefile
	@${ECHO} "=> Adjusting ${WRKSRC}/servGL/serverglx/Imakefile .."
	@cd ${WRKSRC}/servGL/serverglx; \
	${SED} -e 's;tclsh;tclsh8\.0;' <Imakefile >Imakefile.new; \
	${MV} Imakefile.new Imakefile
.endif

#
#  before 'build':
#
#  . build a glx aware Mesa lib
#  . create makefiles (old IMAKE style configuration)
#
pre-build:
.if defined(PATCH_XFREE)
	@${ECHO} "=> Building and installing XFree86-${XFREEVER} with GLX support .."
	cd ${XFREEDIR}/../..; \
	${MAKE} all install
.endif
.if defined(PATCH_MESA)
	@${ECHO} "=> Building and installing Mesa-${MESAVER} with GLX support .."
	cd ${MESADIR}/../..; \
	${MAKE} all install
.endif
.if !defined(GNU_CONFIGURE)
	@${ECHO} "=> Creating makefiles .."
	cd ${WRKSRC}; \
	${XMKMF}; \
	${MAKE} Makefile; \
	${MAKE} Makefiles
.endif

#
#  before 'install':
#
#  . check for proper installed XFree86 version (3.3.4 or higher)
#  . check for glx installation (please deinstall)
#  . check for Mesa 3.0 installtion (please deinstall)
#
pre-install:
	@${ECHO} "=> Checking XFree86 installation .."
	@if \
	  pkg_info -e "XFree86-3.3.4"; \
	then \
	  ${ECHO} "Found XFree86 3.3.4 - this port should still work"; \
	elif \
	  pkg_info -e "XFree86-3.3.5"; \
	then \
	  ${ECHO} "OK, found XFree86 3.3.5 - this port should work"; \
	elif \
	  pkg_info -e "XFree86-3.3.6"; \
	then \
	  ${ECHO} "Found XFree86 3.3.6 - this port should work"; \
	elif \
	  pkg_info -e "XFree86-3.3.3.1"; \
	then \
	  ${ECHO} ""; \
	  ${ECHO} "This port will work only if your XFree86 3.3.3.1 version"; \
	  ${ECHO} "has been patched for use with glx!"; \
	  ${ECHO} ""; \
	  ${ECHO} "Visit 'http://people.FreeBSD.org/~3d' for more information"; \
	  ${ECHO} ""; \
	  ${ECHO} "(We continue with fingers crossed)"; \
	  ${ECHO} ""; \
	else \
	  ${ECHO} ""; \
	  ${ECHO} "This port depends on having a proper version of XFree86"; \
	  ${ECHO} "installed - preferably ${XFREEVER}!"; \
	  ${ECHO} ""; \
	  ${ECHO} "Visit 'http://people.FreeBSD.org/~3d' for more information"; \
	  ${ECHO} ""; \
	  ${ECHO} "Aborting.."; \
	  ${FALSE} ; \
	fi

#
#  after 'install':
#
#  . install some docs
#  . move old Mesa lib away (old IMAKE style configuration)
#  . check XFree86 configuration file for colordepth (RIVA only)
#  . check XFree86 configuration file for glx module
#  . give some hints
#
post-install:
.if !defined(NOPORTDOCS)
	@${ECHO} "=> Installing documentation .."
	${MKDIR} ${PREFIX}/share/doc/riva-glx
	${INSTALL_MAN} ${DISTDIR}/${DIST_SUBDIR}/riva-x-glx.faq.bz2 ${PREFIX}/share/doc/riva-glx
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/riva-glx
	${INSTALL_MAN} ${WRKSRC}/tested.html ${PREFIX}/share/doc/riva-glx

.endif
.if !defined(GNU_CONFIGURE)
	@${ECHO} "=> Adjusting links .."
	-${MV} ${X11BASE}/lib/libMesaGL.a ${X11BASE}/lib/libMesaGL.a.old
	-${MV} ${X11BASE}/lib/libMesaGL.so.14 ${X11BASE}/lib/libMesaGL.so.14.old
	-${LN} -s ${X11BASE}/lib/libGL.a ${X11BASE}/lib/libMesaGL.a
	-${LN} -s ${X11BASE}/lib/libGL.so.1 ${X11BASE}/lib/libMesaGL.so.14
.endif
.if !defined(CHIPSET_3D) || ${CHIPSET_3D} == RIVA
	@${ECHO} "=> Checking for \"DefaultColorDepth\" in ${XFCONFIG} .."
	@${ECHO} ""
	@if \
	  ${GREP} '^ *DefaultColorDepth *1[56] *$$' ${XFCONFIG}; \
	then \
	  ${ECHO} ""; \
	  ${ECHO} "Found something."; \
	else \
	  ${ECHO} "Nope, nothing found - please use"; \
	  ${ECHO} ""; \
	  ${ECHO} "    DefaultColorDepth 16"; \
	  ${ECHO} ""; \
	  ${ECHO} "or"; \
	  ${ECHO} ""; \
	  ${ECHO} "    DefaultColorDepth 15"; \
	  ${ECHO} ""; \
	  ${ECHO} "in your ${XFCONFIG} file with your RIVA card!"; \
	fi
.endif
	@${ECHO} "=> Checking for Section \"Module\" in ${XFCONFIG} .."
	@${ECHO} ""
	@if \
	  ${GREP} -A2 '^ *Section *"Module" *$$' ${XFCONFIG} | \
	  ${GREP} -B1 -A1 '^ *Load *"glx\.so" *$$' | \
	  ${GREP} -B2 '^ *EndSection *$$' | \
	  ${GREP} -A2 '^ *Section *"Module" *$$'; \
	then \
	  ${ECHO} ""; \
	  ${ECHO} "Looks OK to me."; \
	else \
	  ${ECHO} "Nope, not found - please add"; \
	  ${ECHO} ""; \
	  ${ECHO} "  Section \"Module\""; \
	  ${ECHO} "  Load \"glx.so\""; \
	  ${ECHO} "  EndSection"; \
	  ${ECHO} ""; \
	  ${ECHO} "to the end of your ${XFCONFIG} file!"; \
	fi
	@${ECHO} "=> Giving last advice .."
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.post.mk>
