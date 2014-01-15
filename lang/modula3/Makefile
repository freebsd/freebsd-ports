# Created by: marino@FreeBSD.org
# $FreeBSD$

PORTNAME=	modula3
PORTVERSION=	5.8.6
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	https://modula3.elegosoft.com/cm3/releng/ \
		http://downloads.dragonlace.net/m3/ \
		http://downloads.dragonlace.net/m3/:boot
DISTFILES=	${SRCDISTFILE} ${BOOTDIST}

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Critical Mass Modula-3 compiler

LIB_DEPENDS=	libodbc.so:${PORTSDIR}/databases/libiodbc

NEWBOOTDIR=	${WRKDIR}/new-bootstrap/bootstrap
SRCDISTFILE=	cm3-src-all-${PORTVERSION}-REL.tgz
DST1=		m3-bootstrap.AMD64.FREEBSD.92.tar.bz2:boot
DST2=		m3-bootstrap.x86_64.DRAGONFLY.36.tar.bz2:boot

ONLY_FOR_ARCHS=		amd64
CONFLICTS_INSTALL=	cvsup-*

USES=		gmake
USE_PGSQL=	yes
USE_XORG=	xaw xmu xext xt sm ice x11
USE_GL=		gl glu
USE_GCC=	any
NO_MTREE=	yes

MAKE_ENV+=	CM3_INSTALL="${STAGEDIR}${PREFIX}" \
		CM3_DEBUG=yes \
		M3_PORTABLE_RUN_PATH=yes
BOOTCM3=	CM3="${WRKDIR}/bootstrap/bin/cm3"
BUILTCM3=	CM3="${STAGEDIR}${PREFIX}/bin/cm3"
BSCONTENTS=	bin/cm3 bin/cm3cg bin/m3bundle bin/mklib etc/modula3 \
		lib/libm3core.* lib/libm3.* lib/libsysutils.* \
		lib/libpatternmatching.* pkg/m3core pkg/libm3 pkg/sysutils \
		pkg/patternmatching pkg/m3middle pkg/m3objfile pkg/m3linker \
		pkg/m3back pkg/m3front pkg/m3quake pkg/cm3 pkg/mklib

.include <bsd.port.pre.mk>

M3MAKE_ENV=	${MAKE_ENV:C/^LDFLAGS=.*//:C/^CPPFLAGS=.*//}

# for port maintenance, invoke "make makesum PLUS_BOOTSTRAPS=1"
.if defined(PLUS_BOOTSTRAPS)
DISTFILES=	${SRCDISTFILE} ${DST1} ${DST2}
.else

. if ${OPSYS} == FreeBSD
BOOTDIST=	${DST1}
MARCH=		AMD64
.  if !exists(/usr/include/xlocale/_ctype.h)
IGNORE=		the bootstrap compiler only runs on FreeBSD 9.0 or later
.  endif
. endif

. if ${OPSYS} == DragonFly
IGNORE=		modula-3 has not adapted to DragonFly yet
BOOTDIST=	${DST2}
MARCH=		x86_64
. endif

NEWBOOTNAME=	m3-bootstrap.${MARCH}.${OPSYS:U}.${OSREL:S/.//}.tar.bz2
M3TARGET=	${MARCH}_${OPSYS:U}
.endif

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKSRC}
	@(cd ${WRKSRC} && tar -xf ${DISTDIR}/${SRCDISTFILE})
	@(cd ${WRKDIR} && tar -xf ${DISTDIR}/${BOOTDIST:C/:[^:]+$//})

post-patch:
# Use sed -i instead of ${REINPLACE_CMD} because we don't want .bak files
# installed in the final product which comes from config-no-install dir.
	@${SED} -i "" -e 's|/usr/local|${PREFIX}|g' \
	    -e 's|\\\\$$ORIGIN"|${PREFIX}/lib"|' \
	    ${WRKSRC}/m3-sys/cminstall/src/config-no-install/FreeBSD.common
	@${SED} -i "" -e 's|/usr/X11R6|${PREFIX}|g' \
	    ${WRKSRC}/m3-sys/cminstall/src/config-no-install/Unix.common
	@${SED} -i "" -e 's/^SYSTEM_CC = ".* -gs/SYSTEM_CC = "${CC} -gs/' \
	    ${WRKDIR}/bootstrap/etc/modula3/AMD64_FREEBSD \
	    ${WRKSRC}/m3-sys/cminstall/src/config-no-install/AMD64_FREEBSD

do-bootstrap:
	@(cd ${WRKSRC}; ${SETENV} ${M3MAKE_ENV} ${BOOTCM3} SHIP=${TRUE} \
		${SH} scripts/boot-cm3-with-m3.sh onlybuild)
	@${FIND} ${WRKSRC} -name \.M3SHIP -print | ${XARGS} ${SED} -i -e \
		's|/bootstrap/|/stage${PREFIX}/|g'
	@(cd ${WRKSRC}; ${SETENV} ${M3MAKE_ENV} ${BOOTCM3} \
		${SH} scripts/boot-cm3-with-m3.sh ship)
	(cd ${WRKSRC}/m3-sys/cminstall/src/config-no-install && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/etc/modula3)
	${INSTALL_PROGRAM} ${WRKSRC}/m3-sys/cm3/${M3TARGET}/cm3 \
		${STAGEDIR}${PREFIX}/bin
	${ECHO} "INSTALL_ROOT = \"${STAGEDIR}${PREFIX}\"" > \
		${STAGEDIR}${PREFIX}/bin/cm3.cfg
	${ECHO} "include(\"${STAGEDIR}${PREFIX}/etc/modula3/${M3TARGET}\")" >> \
		${STAGEDIR}${PREFIX}/bin/cm3.cfg
	@(cd ${WRKSRC}; ${SETENV} ${M3MAKE_ENV} ${BOOTCM3} \
		${SH} scripts/boot-cm3-with-m3.sh cleanglobal)
	@${ECHO} "======================================"
	@${ECHO} "=====  M3 compiler bootstrapped  ====="
	@${ECHO} "======================================"
	@${ECHO}

do-build: do-bootstrap
	@(cd ${WRKSRC}; ${SETENV} ${M3MAKE_ENV} ${BUILTCM3} \
		${SH} scripts/do-cm3-min.sh buildship)
	@(cd ${WRKSRC}; ${SETENV} ${M3MAKE_ENV} ${BUILTCM3} \
		${SH} scripts/do-cm3-std.sh buildship)
	@(cd ${WRKSRC}; ${SETENV} ${M3MAKE_ENV} ${BUILTCM3} \
		${SH} scripts/do-cm3-caltech-parser.sh buildship)

do-install:
	${FIND} ${STAGEDIR}${PREFIX}/pkg -type f -perm +111 -not -name cm3 | \
		${XARGS} ${CHMOD} -x
	${ECHO} "INSTALL_ROOT = \"${PREFIX}\"" > \
		${STAGEDIR}${PREFIX}/bin/cm3.cfg
	${ECHO} "include(\"${PREFIX}/etc/modula3/${M3TARGET}\")" >> \
		${STAGEDIR}${PREFIX}/bin/cm3.cfg
	${MKDIR} ${STAGEDIR}${PREFIX}/share/examples/bin \
	         ${STAGEDIR}${PREFIX}/share/doc
	${MV} ${STAGEDIR}${PREFIX}/examples \
		${STAGEDIR}${PREFIX}/share/examples/modula3
	${MV} ${STAGEDIR}${PREFIX}/www ${STAGEDIR}${PREFIX}/share/doc/modula3
	${MV} ${STAGEDIR}${PREFIX}/bin/Cube \
		${STAGEDIR}${PREFIX}/bin/Calculator \
		${STAGEDIR}${PREFIX}/bin/fisheye \
		${STAGEDIR}${PREFIX}/share/examples/bin

# The pkg-plist is well over 6000 entries, so let's just autogen it instead
post-install:
	cd ${STAGEDIR}${PREFIX}; ${FIND} * \( -type f -or -type l \) | \
	   ${SORT} | ${SED} -e 's/^man\/man[1578]\/.*[1578]$$/&.gz/' \
	   > ${TMPPLIST}
	cd ${STAGEDIR}${PREFIX}; ${FIND} * -type d | ${SORT} -r | \
	   ${SED} -e '/^bin$$/d' -e '/^lib$$/d' -e '/^pkg$$/d' \
	   -e '/^share\/examples$$/d' -e '/^share\/doc$$/d' -e '/^share$$/d' \
	   -e '/^etc$$/d' -e '/^man\/man[1578]$$/d' -e '/^man$$/d' \
	   -e 's/^/@dirrm /g' >> ${TMPPLIST}
	@echo "@unexec rmdir %D/share/doc 2>/dev/null || true" >> ${TMPPLIST}
	@echo "@unexec rmdir %D/share/examples 2>/dev/null || true" >> ${TMPPLIST}
	@echo "@unexec rmdir %D/share 2>/dev/null || true" >> ${TMPPLIST}
	@echo "@unexec rmdir %D/bin 2>/dev/null || true" >> ${TMPPLIST}
	@echo "@unexec rmdir %D/etc 2>/dev/null || true" >> ${TMPPLIST}
	@echo "@unexec rmdir %D/lib 2>/dev/null || true" >> ${TMPPLIST}
	@echo "@unexec rmdir %D/man/man8 2>/dev/null || true" >> ${TMPPLIST}
	@echo "@unexec rmdir %D/man/man7 2>/dev/null || true" >> ${TMPPLIST}
	@echo "@unexec rmdir %D/man/man5 2>/dev/null || true" >> ${TMPPLIST}
	@echo "@unexec rmdir %D/man/man1 2>/dev/null || true" >> ${TMPPLIST}
	@echo "@unexec rmdir %D/man 2>/dev/null || true" >> ${TMPPLIST}
	@echo "@unexec rmdir %D/pkg 2>/dev/null || true" >> ${TMPPLIST}

# to create a new bootstrap, invoke "make stage NEW_BOOTSTRAP=1"
.if defined(NEW_BOOTSTRAP)
post-stage:
	@${RM} -rf ${NEWBOOTDIR}
	@${MKDIR} ${NEWBOOTDIR}/bin ${NEWBOOTDIR}/lib \
	          ${NEWBOOTDIR}/pkg ${NEWBOOTDIR}/etc
.for X in ${BSCONTENTS}
	@${CP} -a ${STAGEDIR}${PREFIX}/${X} ${NEWBOOTDIR}/${X:H}/
.endfor
	${ECHO} "INSTALL_ROOT = path() & \"/..\"" \
		>  ${NEWBOOTDIR}/bin/cm3.cfg
	${ECHO} "include(path() & \"/../etc/modula3/${M3TARGET}\")" \
		>> ${NEWBOOTDIR}/bin/cm3.cfg
	@${FIND} ${NEWBOOTDIR} -type f -perm +111 | ${XARGS} ${STRIP_CMD}
	(cd ${NEWBOOTDIR}/.. ; tar -cyf ${NEWBOOTNAME} bootstrap)
.endif

.include <bsd.port.post.mk>
