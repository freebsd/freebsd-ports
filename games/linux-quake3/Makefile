# New ports collection makefile for:	Quake 3 Arena Dedicated Server
# Date created:				Sun Jun  3 00:52:38 EDT 2001
# Whom:					pat@databits.net
#
# $FreeBSD$
#

PORTNAME=	quake3
PORTVERSION=	1.32c
CATEGORIES=	games linux
MASTER_SITES=	${MASTER_SITE_IDSOFTWARE:S|$|quake3/linux/:data|} \
		${MASTER_SITE_IDSOFTWARE:S|$|quake3/:patch|}
PKGNAMEPREFIX=	linux-
DISTFILES=	${Q3DATAFILE}:data \
		${Q3PATCHFILE}:patch
DIST_SUBDIR=	${Q3PKGNAMEPREFIX}data

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quake III Arena for Linux

USE_ZIP=	yes
USE_LINUX=	yes
NO_WRKSUBDIR=	yes

OPTIONS=	CLIENT "Install client" on \
		DEDICATED "Install dedicated server" on \
		PUNKBUSTER "Install PunkBuster" on \
		SMP "Install SMP (threaded) client" on

PLIST_SUB+=	LIBDIR="${LIBDIR:S/${PREFIX}\///}"
LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}

LIBDIR=		${PREFIX}/libexec/${PKGNAMEPREFIX}${PORTNAME}
Q3DATAFILE=	linuxq3apoint-1.32b-3.x86.run
Q3PATCHFILE=	quake3-${PORTVERSION}.zip

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && ${TAIL} +356 ${_DISTDIR}/${Q3DATAFILE} | \
		${TAR} zxf -
	@${UNZIP_CMD} -qo ${_DISTDIR}/${Q3PATCHFILE} -d ${WRKDIR}

post-extract:
.for f in q3ded quake3.x86 quake3-smp.x86
	@${MV} "${WRKSRC}/Quake III Arena 1.32c/linux/${f}" \
		${WRKSRC}/bin/Linux/x86/${f}
.endfor

.include "${.CURDIR}/../quake3-data/Makefile.include"

.include <bsd.port.pre.mk>

.if defined(WITHOUT_CLIENT) && defined(WITHOUT_DEDICATED) && \
    defined(WITHOUT_SMP)
IGNORE=		needs at least one of the CLIENT, DEDICATED and SMP options
.endif

.if !defined(WITHOUT_DEDICATED)
PROGS+=		q3ded
PLIST_SUB+=	DEDICATED=""
.else
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if !defined(WITHOUT_CLIENT)
PROGS+=		quake3.x86
PLIST_SUB+=	CLIENT=""
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if !defined(WITHOUT_PUNKBUSTER)
PLIST_SUB+=	PUNKBUSTER=""
.else
PLIST_SUB+=	PUNKBUSTER="@comment "
.endif

.if !defined(WITHOUT_SMP)
PROGS+=		quake3-smp.x86
PLIST_SUB+=	SMP=""
.else
PLIST_SUB+=	SMP="@comment "
.endif

do-build:
.for f in ${PROGS}
	@(${ECHO_CMD} "#!${SH}"; \
		${ECHO_CMD} "cd ${DATADIR} || exit 1"; \
		${ECHO_CMD} 'exec ${LIBDIR}/${f:R} "$$@"') > ${WRKDIR}/${f:R}
.endfor

do-install:
	@${MKDIR} ${LIBDIR}
.for f in ${PROGS}
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/Linux/x86/${f} ${LIBDIR}/${f:R}
	@${INSTALL_SCRIPT} ${WRKDIR}/${f:R} ${PREFIX}/bin/linux-${f:R}
.endfor
.if !defined(WITHOUT_PUNKBUSTER)
	@${CP} -Rp ${WRKSRC}/pb ${DATADIR}
	@${RM} ${DATADIR}/pb/PB_EULA.txt
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README-linux.txt ${DOCSDIR}
	@${CP} -Rp ${WRKSRC}/Docs/LinuxFAQ ${DOCSDIR}
.   if !defined(WITHOUT_PUNKBUSTER)
	@${CP} -Rp ${WRKSRC}/Docs/PunkBuster ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/pb/PB_EULA.txt ${DOCSDIR}/PunkBuster
.   endif
.endif

.include <bsd.port.post.mk>
