# New ports collection makefile for: ilu
# Date created:         29.9.1997
# Whom:                 cracauer@cons.org "Martin Cracauer"
#
# $FreeBSD$
#

PORTNAME=	ilu
PORTVERSION=	2.0a13
CATEGORIES=	devel
MASTER_SITES=	ftp://parcftp.xerox.com/pub/ilu/2.0a13/ \
		http://www2.cons.org:8000/freebsd-distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	cracauer
DISTNAME=	${PORTNAME}-2.0alpha13

PATCH_SITES=	http://www2.cons.org:8000/freebsd-distfiles/ \
		${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	cracauer
PATCHFILES=	${DISTNAME}-patches.html.gz

MAINTAINER=	cracauer@cons.org

BROKEN=		"Does not build"

BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake

# The FreeBSD port uses its own shared library patches. The native
# ILU support is incomplete and disabled here.
CONFIGURE_ARGS=	--enable-http-protocol --enable-os-threads=posix \
		--disable-kernel-shared-library --disable-c-shared-library \
		--disable-cplusplus-shared-libary

NO_WRKSUBDIR=	yes
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}/ilu

INSTALL_TARGET=	Install
PLIST=		${WRKSRC}/PLIST

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
SHLIBPATCH=files/shlib-elf.patch
# The FreeBSD Java Development Kit is still in aout object format.
# You might want to enable it if you have an ELF JDK and/or build
# a seperate aout ILU runtime to use with Java.
CONFIGURE_ARGS+=	--disable-java-support
.else
SHLIBPATCH=files/shlib-aout.patch
# Java support on -stable does not work (ILU runtime dumps core).
# You might want to enable it if you know what you are doing.
# Taking -O out of patches/patch-1-cra-cflags may also help.
CONFIGURE_ARGS+=	--disable-java-support
.endif

# Startup script, run at boot time
startup_dir=	${PREFIX}/etc/rc.d
startup_script=	${startup_dir}/50.ilu.sh

pre-patch:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/stubbers/parser/ilu.bison \
		${WRKSRC}/stubbers/parser/genregs.c \
		${WRKSRC}/stubbers/parser/iluparse.c.dist \
		${WRKSRC}/stubbers/c/cstubber.h \
		${WRKSRC}/stubbers/idl/idlparser.y \
		${WRKSRC}/stubbers/idl/bison.skel \
		${WRKSRC}/stubbers/idl/idlparser.c.dist

post-extract:
	${CHMOD} -R u+w ${WRKDIR}

post-patch:
	${PATCH} ${PATCH_DIST_ARGS} < ${SHLIBPATCH}

do-install:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})
	# Empty dir, but we really need it
	${ECHO_CMD} @exec ${MKDIR} %D/ilu/lib/binding > ${PLIST}
	${ECHO_CMD} @unexec ${RM} -r %D/ilu/lib/binding >> ${PLIST}
	${ECHO_CMD} @exec ${CHMOD} 1777 %D/ilu/lib/binding >> ${PLIST}
	${ECHO_CMD} @exec ${LDCONFIG} -m %D/ilu/lib >> ${PLIST}
	# Empty dirs we don't need
	${RMDIR} ${PREFIX}/ilu/man/man[358]
	${RMDIR} ${PREFIX}/ilu/lisp
	-${RMDIR} ${PREFIX}/ilu/examples/javatest1/javastubs
	(cd ${PREFIX} ; find ilu -type f) >> ${PLIST}
	(cd ${PREFIX} ; find ilu -type d) | ${AWK} '{print "@dirrm " $$1}' \
		| tail -r | ${GREP} -v lib/binding >> ${PLIST}
	(cd ${PREFIX}/ilu/bin ; for file in * ; do \
		${LN} -fs ${PREFIX}/ilu/bin/$$file ${PREFIX}/bin/. ; \
		${ECHO_CMD} bin/$$file ; \
		done) >> ${PLIST}
	(cd ${PREFIX}/ilu/man/man1 ; for file in * ; do \
		${LN} -fs ${PREFIX}/ilu/man/man1/$$file ${PREFIX}/man/man1/. ; \
		${ECHO_CMD} man/man1/$$file ; \
		done) >> ${PLIST}
	${ECHO_CMD} etc/rc.d/50.ilu.sh >> ${PLIST}
	${ECHO} "Installing ${startup_script} file"
	test -d ${startup_dir} || ${MKDIR} ${startup_dir}
	${ECHO_CMD} "#!/bin/sh" > ${startup_script}
	${ECHO_CMD} "${ECHO_CMD} -n ' ILU-shlibs'" >> ${startup_script}
	${ECHO_CMD} "${LDCONFIG} -m ${PREFIX}/ilu/lib" >> ${startup_script}
	${CHMOD} 755 ${startup_script};
	${startup_script}

.include <bsd.port.post.mk>
