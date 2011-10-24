# ex:ts=8
# Ports collection makefile for:  Sather
# Date created:			  Mon Oct 31 22:04:12 PST 1994
# Whom:				  hsu
#
# $FreeBSD$
#

PORTNAME=	sather
PORTVERSION=	1.2.2
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sather compiler

#
# NOTE: currently build fails with threaded Tk
#
LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84 \
		gc-redirect.1:${PORTSDIR}/devel/boehm-gc-redirect
BUILD_DEPENDS=	${LOCALBASE}/bin/libtool:${PORTSDIR}/devel/libtool

USE_BZIP2=	yes
USE_GMAKE=	yes
ALL_TARGET=	full optional
MAN1=		sabrowse.1 sacomp.1

INFO=		sather sather-mode sather-tutorial

SAT_CFLAGS=	${CFLAGS} -I. \
		-I../System/Common \
		-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/tcl8.4 -I${LOCALBASE}/include/tk8.4
SAT_LIBS=	-L${LOCALBASE}/lib -lgc-redirect -lm
SAT_LIBDIR=	${PREFIX}/lib/sather

OPTIONS=	EMACS "Install Emacs syntax files" off

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900000
BROKEN=		segfaults during build on 9.X
.endif

post-extract:
#
#	Precompiled binaries are for Linux only
#
	${RM} -f ${WRKSRC}/Boot/sacomp.code/*.o

post-patch:
	@${REINPLACE_CMD} -E \
		-e "s,/usr/lib/sather,${SAT_LIBDIR}," \
		-e "s,/usr/X11R6,${LOCALBASE}," \
		-e "s,/usr/X11R6,${LOCALBASE}," \
		${WRKSRC}/Boot/sacomp.code/strings.c \
		${WRKSRC}/Doc/Installation.html \
		${WRKSRC}/Doc/man/man1/sabrowse.1 \
		${WRKSRC}/Doc/man/man1/sacomp.1 \
		${WRKSRC}/Library/System/unix.sa \
		${WRKSRC}/System/Platforms/X/Platform.module \
		${WRKSRC}/System/Platforms/tcltk/startup.tcl \
		${WRKSRC}/debian/bin-wrapper

	@${REINPLACE_CMD} -E \
		-e "s,(TK_LIB_NAME[[:space:]]*=[[:space:]]*).*,\1tk84," \
		-e "s,(TCL_LIB_NAME[[:space:]]*=[[:space:]]*).*,\1tcl84," \
		${WRKSRC}/System/Platforms/tcltk/Make.target.inc

	@${REINPLACE_CMD} -E \
		-e 's,(VERSION:[[:space:]]*).*,\1"${PORTVERSION}";,' \
		-e 's,(C_COMPILER:[[:space:]]*).*,\1"${CC}";,' \
		-e 's,(CC_OPTIONS:[[:space:]]*).*,\1"${SAT_CFLAGS}";,' \
		-e 's,(GC_LINK:[[:space:]]*).*,\1"${SAT_LIBS}";,' \
		-e 's,(CC_OPTIMIZE_FLAG:[[:space:]]*).*,\1""\,"${CFLAGS}";,' \
		-e 's,(MAKE_COMMAND:[[:space:]]*).*,\1"${GMAKE}";,' \
		-e 's,(FORTRAN_APPEND_UNDERSCORE:[[:space:]]*).*,\1"true";,' \
		-e 's,CONFIG_PLATFORMS,unix,' \
		-e 's,CONFIG_DEFAULT_PLATFORM,freebsd,' \
		${WRKSRC}/System/Common/CONFIG.proto \
		${WRKSRC}/System/Platforms/freebsd/CONFIG

	@${REINPLACE_CMD} -E \
		-e "s,(DEFAULT_PLATFORM[[:space:]]*=[[:space:]]*).*,\1freebsd,"\
		-e "s,(CPP[[:space:]]*=[[:space:]]*).*,\1/usr/bin/cpp -P," \
		-e "s,(CC[[:space:]]*=[[:space:]]*).*,\1${CC}," \
		-e "s,(CFLAGS[[:space:]]*=[[:space:]]*).*,\1${SAT_CFLAGS}," \
		-e "s,(LIBS[[:space:]]*=[[:space:]]*).*,\1${SAT_LIBS}," \
		${WRKSRC}/Makefile ${WRKSRC}/Boot/sacomp.code/Makefile

	@${REINPLACE_CMD} -E \
		-e 's,/usr/bin/tclsh,${LOCALBASE}/bin/tclsh8.4,' \
			${WRKSRC}/Browser/Web/*
#
# Don't generate cpp comments - Sather won't like it
#
	@${REINPLACE_CMD} -E \
		-e 's,#(CPP[[:space:]]*=[[:space:]]*).*,\1/usr/bin/cpp -P,' \
		${WRKSRC}/System/Common/Makefile
#
# We have this function in stdlib
#
	@${ECHO_CMD} \"abort2\" >> ${WRKSRC}/System/FORBID

post-build:
.for file in sather-tutorial.texinfo sather-mode.texinfo sather.texinfo
	cd ${WRKSRC}/Emacs && makeinfo --no-split ${file}
.endfor

do-install:
	@${MKDIR} ${SAT_LIBDIR}/Bin
.for file in sabrowse sacomp
	${INSTALL_PROGRAM} ${WRKSRC}/Bin/${file} ${SAT_LIBDIR}/Bin
.endfor
.for file in PP gen_html saprep
	${INSTALL_SCRIPT} ${WRKSRC}/Bin/${file} ${SAT_LIBDIR}/Bin
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/debian/bin-wrapper ${SAT_LIBDIR}/Bin
.for link in sabrowse sacomp
	${LN} -sf ${SAT_LIBDIR}/Bin/bin-wrapper ${PREFIX}/bin/${link}
.endfor
.for obj in Browser Library System/Common System/Debug System/FORBID \
	System/Platforms/X System/Platforms/dualgui System/Platforms/f77 \
	System/Platforms/freebsd System/Platforms/gui System/Platforms/tcltk
	${TAR} -C ${WRKSRC} -cf - \
		--exclude "ActiveThreads" --exclude "Brahma" \
		--exclude "CONFIG.proto" --exclude "Siva" \
		--exclude "dual_gui_server.code" --exclude "*.bak" \
		--exclude "*.config" --exclude "*.orig" \
		--exclude "*Makefile*" ${obj} | \
		${TAR} -C ${SAT_LIBDIR} --unlink -xf -
.endfor

#
# Permissions safety
#
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${SAT_LIBDIR}
	@${FIND} ${SAT_LIBDIR}/ -type f ! -perm +111 -exec ${CHMOD} \
		${SHAREMODE} {} \;
	@${FIND} ${SAT_LIBDIR}/ -type f -perm +111 -exec ${CHMOD} \
		${BINMODE} {} \;
	@${FIND} ${SAT_LIBDIR}/ -type d -exec ${CHMOD} 755 {} \;

#
# Generate PLIST
#
	@${FIND} -d ${SAT_LIBDIR}/ -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} -d ${SAT_LIBDIR}/ -type d | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.for FILE in sabrowse sacomp
	@${ECHO_CMD} \
		"@exec ${LN} -sf %D/lib/sather/Bin/bin-wrapper %D/bin/${FILE}"\
		>> ${TMPPLIST}
	@${ECHO_CMD} "bin/${FILE}" >> ${TMPPLIST}
.endfor

.for file in sabrowse.1 sacomp.1
	${INSTALL_MAN} ${WRKSRC}/Doc/man/man1/${file} ${MANPREFIX}/man/man1
.endfor
.for file in ${INFO}
	${INSTALL_DATA} ${WRKSRC}/Emacs/${file}.info ${PREFIX}/info
.endfor
.if defined(WITH_EMACS)
. for file in hl319.el sather-lib.el sather-module.el sather.el
	${INSTALL_DATA} ${WRKSRC}/Emacs/${file} ${PREFIX}/share/emacs/site-lisp
	@${ECHO_CMD} "share/emacs/site-lisp/${file}" >> ${TMPPLIST}
. endfor
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/Doc && ${COPYTREE_SHARE} "*" ${DOCSDIR} \
		"! -regex .*man.* ! -regex .*GPL ! -regex .*\.bak")
.endif

.include <bsd.port.post.mk>
