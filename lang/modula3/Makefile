# Created by: marino@FreeBSD.org
# $FreeBSD$

PORTNAME=	modula3
PORTVERSION=	5.10.0
PORTREVISION=	9
CATEGORIES=	lang
MASTER_SITES=	http://downloads.dragonlace.net/m3/:boot
DISTFILES=	${SRCDISTFILE} ${BOOTDIST}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Critical Mass Modula-3 compiler

LICENSE=	DECM3
LICENSE_NAME=	CM3 License defined by DEC and Critical Mass copyrights
LICENSE_FILE=	${WRKSRC}/COM_LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libodbc.so:databases/unixODBC

NEWBOOTDIR=	${WRKDIR}/new-bootstrap/bootstrap
SRCDISTFILE=	modula3-cm3-${PORTVERSION}-${GH_TAGNAME}_GH0.tar.gz
DST1=		m3-bootstrap.AMD64.FREEBSD.92.tar.bz2:boot
DST2=		m3-bootstrap.x86_64.DRAGONFLY.36.tar.bz2:boot

ONLY_FOR_ARCHS=		amd64
PORTSCOUT=		ignore:1

USE_GITHUB=	yes
GH_ACCOUNT=	modula3
GH_PROJECT=	cm3
GH_TAGNAME=	b2ce705

USES=		gmake pgsql python:2.7,build
USE_XORG=	xaw xmu xext xt sm ice x11
USE_GL=		gl glu
USE_GCC=	yes
NO_MTREE=	yes

MAKE_ENV=	CM3_DEBUG=yes \
		M3_PORTABLE_RUN_PATH=yes
INTERMED=	${WRKDIR}/intermediate
BOOTCM3=	CM3="${WRKDIR}/bootstrap/bin/cm3"
PORTDOCS=	www license
STRIPPKG=	m3staloneback/m3back \
		libdump/libdump \
		cmpfp/cmpfp \
		formsview/formsview \
		vorun/vorun \
		pkl-fonts/PklFonts \
		hack/dummy \
		test/test

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

M3BOOT_ENV=	${MAKE_ENV:C/^LDFLAGS=.*//:C/^CPPFLAGS=.*//} \
		${BOOTCM3} STAGE=${INTERMED:Q}

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

NEWBOOTNAME=	m3-bootstrap.${MARCH}.${OPSYS:tu}.${OSREL:S/.//}.tar.bz2
M3TARGET=	${MARCH}_${OPSYS:tu}
PLIST_SUB+=	T=${M3TARGET} P=cm3/pkg B=cm3/bin L=cm3/lib
.endif

post-extract:
	@(cd ${WRKSRC} && ${CAT} COPYRIGHT-DEC COPYRIGHT-CMASS > COM_LICENSE)

post-patch:
	@${REINPLACE_CMD} -i "" -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/m3-sys/cminstall/src/config-no-install/FreeBSD.common
	@${REINPLACE_CMD} -i "" \
		-e 's|/usr/local|${LOCALBASE}|g' \
		-e 's|/usr/X11R6|${LOCALBASE}|g' \
		${WRKSRC}/m3-sys/cminstall/src/config-no-install/Unix.common
	@${REINPLACE_CMD} -i "" \
		-e 's/^SYSTEM_CC = ".* -gs/SYSTEM_CC = "${CC} -gs/' \
		-e 's|as -64|${AS} -64|' \
		${WRKDIR}/bootstrap/etc/modula3/AMD64_FREEBSD \
		${WRKSRC}/m3-sys/cminstall/src/config-no-install/AMD64_FREEBSD
	@${REINPLACE_CMD} -e 's|m3cc, bin|bin|' \
		${WRKDIR}/bootstrap/etc/modula3/cm3cfg.common
	@${GREP} -rl 'bin/env python' ${WRKSRC}/m3-sys ${WRKSRC}/scripts | \
		${XARGS} ${REINPLACE_CMD} \
		-e 's|/usr/bin/env python|${PYTHON_CMD}|'

do-build:
	(cd ${WRKSRC} && ${SETENV} ${M3BOOT_ENV} \
		${PYTHON_CMD} scripts/python/make-dist.py)

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -a ${INTERMED}/all-dist ${STAGEDIR}${PREFIX}/cm3
	${MV} ${STAGEDIR}${PREFIX}/cm3/man ${STAGEDIR}${PREFIX}/
	${MV} ${STAGEDIR}${PREFIX}/cm3/www ${STAGEDIR}${DOCSDIR}/
	${MV} ${STAGEDIR}${PREFIX}/cm3/license ${STAGEDIR}${DOCSDIR}/
	${CHMOD} -x ${STAGEDIR}${PREFIX}/cm3/pkg/m3back/src/M3C.i3 \
		${STAGEDIR}${PREFIX}/cm3/pkg/m3core/src/C/Common/Csetjmp.i3
	(cd ${STAGEDIR}${PREFIX}/cm3/bin && ${FIND} * -type f -perm +111 | \
		${SED} -E '/^(obliq|obliqsrv|recordheap)$$/d' | \
		${XARGS} ${STRIP_CMD})
	${FIND} ${STAGEDIR}${PREFIX}/cm3/lib -type f -perm +111 | \
		${XARGS} ${STRIP_CMD}
.for PACKAGE in ${STRIPPKG}
	(cd ${STAGEDIR}${PREFIX}/cm3/pkg/${PACKAGE:H}/${M3TARGET} && \
		${STRIP_CMD} ${PACKAGE:T} && \
		${MV} ${PACKAGE:T} ../../../bin/ && \
		${LN} -s ../../../bin/${PACKAGE:T} .)
.endfor
	(cd ${STAGEDIR}${PREFIX}/cm3/pkg/cm3/${M3TARGET} && \
		${RM} cm3 && ${LN} -s ../../../bin/cm3 .)

new-bootstrap:
	@${RM} -r ${NEWBOOTDIR}
	@${MKDIR} ${NEWBOOTDIR:H}
	${CP} -a ${INTERMED}/min-dist ${NEWBOOTDIR}
	@${FIND} ${NEWBOOTDIR} -type f -perm +111 | \
		${SED} -E '/Csetjmp.i3$$/d' | ${XARGS} ${STRIP_CMD}
	(cd ${NEWBOOTDIR}/.. ; tar -cyf ${NEWBOOTNAME} bootstrap)

.include <bsd.port.post.mk>
