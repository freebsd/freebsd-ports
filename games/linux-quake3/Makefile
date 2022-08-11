PORTNAME=	quake3
PORTVERSION=	1.32c
CATEGORIES=	games linux
MASTER_SITES=	IDSOFTWARE/quake3/linux/:data \
		IDSOFTWARE/quake3/:patch
PKGNAMEPREFIX=	linux-
DISTFILES=	${Q3DATAFILE}:data \
		${Q3PATCHFILE}:patch
DIST_SUBDIR=	${Q3PKGNAMEPREFIX}data

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quake III Arena for Linux

# Converted from RESTRICTED
LICENSE=	Loki
LICENSE_NAME=	Loki
LICENSE_TEXT=	Restrictive license by Loki Software
LICENSE_PERMS=	auto-accept

USES=		linux zip:infozip
NO_WRKSUBDIR=	yes

OPTIONS_MULTI=	TYPE
OPTIONS_MULTI_TYPE=	CLIENT DEDICATED SMP
OPTIONS_DEFINE=	PUNKBUSTER DOCS
OPTIONS_DEFAULT=	CLIENT DEDICATED PUNKBUSTER SMP

OPTIONS_SUB=	yes

CLIENT_DESC=	Install client
DEDICATED_DESC=	Install dedicated server
PUNKBUSTER_DESC=	Install PunkBuster
SMP_DESC=	Install SMP (threaded) client

PLIST_SUB+=	LIBDIR="libexec/${PKGNAMEPREFIX}${PORTNAME}"

LIBDIR=		${PREFIX}/libexec/${PKGNAMEPREFIX}${PORTNAME}
Q3DATAFILE=	linuxq3apoint-1.32b-3.x86.run
Q3PATCHFILE=	quake3-${PORTVERSION}.zip

do-extract:
	@cd ${WRKSRC} && ${TAIL} +356 ${_DISTDIR}/${Q3DATAFILE} | \
		${TAR} zxf -
	@${UNZIP_CMD} -qo ${_DISTDIR}/${Q3PATCHFILE} -d ${WRKSRC}

post-extract:
.for f in q3ded quake3.x86 quake3-smp.x86
	@${MV} "${WRKSRC}/Quake III Arena 1.32c/linux/${f}" \
		${WRKSRC}/bin/Linux/x86/${f}
.endfor

.include "${.CURDIR}/../quake3-data/Makefile.include"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEDICATED}
PROGS+=		q3ded
.endif

.if ${PORT_OPTIONS:MCLIENT}
PROGS+=		quake3.x86
.endif

.if ${PORT_OPTIONS:MSMP}
PROGS+=		quake3-smp.x86
.endif

do-build:
.for f in ${PROGS}
	@(${ECHO_CMD} "#!${SH}"; \
		${ECHO_CMD} "cd ${DATADIR} || exit 1"; \
		${ECHO_CMD} 'exec ${LIBDIR}/${f:R} "$$@"') > ${WRKDIR}/${f:R}
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${LIBDIR}
.for f in ${PROGS}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/Linux/x86/${f} ${STAGEDIR}${LIBDIR}/${f:R}
	${INSTALL_SCRIPT} ${WRKDIR}/${f:R} ${STAGEDIR}${PREFIX}/bin/linux-${f:R}
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
.if ${PORT_OPTIONS:MPUNKBUSTER}
	@${CP} -Rp ${WRKSRC}/pb ${STAGEDIR}${DATADIR}
	@${RM} ${STAGEDIR}${DATADIR}/pb/PB_EULA.txt
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README-linux.txt ${STAGEDIR}${DOCSDIR}
	${CP} -Rp ${WRKSRC}/Docs/LinuxFAQ ${STAGEDIR}${DOCSDIR}
	${CP} -Rp ${WRKSRC}/Docs/PunkBuster ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/pb/PB_EULA.txt ${STAGEDIR}${DOCSDIR}/PunkBuster

.include <bsd.port.mk>
