# New ports collection makefile for:	Quake 3 Arena Dedicated Server
# Date created:				Sun Jun  3 00:52:38 EDT 2001
# Whom:					pat@databits.net
#
# $FreeBSD$
#

PORTNAME=	quake3
DISTVERSION=	1.32b-3
CATEGORIES=	games linux
MASTER_SITES=	${MASTER_SITE_IDSOFTWARE}
MASTER_SITE_SUBDIR=	quake3/linux
PKGNAMEPREFIX=	linux-
DISTNAME=	linuxq3apoint-${DISTVERSION}.x86
EXTRACT_SUFX=	.run
DIST_SUBDIR=	${Q3PKGNAMEPREFIX}data

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quake III Arena for Linux

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
NO_WRKSUBDIR=	yes

OPTIONS=	CLIENT "Install OpenGL client" on \
		PUNKBUSTER "Install PunkBuster" on \
		SMP "Install threaded version" on

BINDIR=		${PREFIX}/libexec/${PKGNAMEPREFIX}${PORTNAME}
PLIST_SUB+=	BINDIR="${BINDIR:S/${PREFIX}\///}"

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && ${TAIL} +356 ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
		${TAR} zxf -

.include "${.CURDIR}/../quake3-data/Makefile.include"

.include <bsd.port.pre.mk>

PROGS=		q3ded

.if defined(WITH_CLIENT)
PROGS+=		quake3.x86
PLIST_SUB+=	CLIENT=""
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if defined(WITH_PUNKBUSTER)
PLIST_SUB+=	PUNKBUSTER=""
.else
PLIST_SUB+=	PUNKBUSTER="@comment "
.endif

.if defined(WITH_SMP)
PROGS+=		quake3-smp.x86
PLIST_SUB+=	SMP=""
.else
PLIST_SUB+=	SMP="@comment "
.endif

do-build:
.for f in ${PROGS}
	@(${ECHO_CMD} "#!${SH}"; \
		${ECHO_CMD} "cd ${DATADIR} || exit 1"; \
		${ECHO_CMD} "exec ${BINDIR}/${f:R} \"$$@\"") > ${WRKDIR}/${f:R}
.endfor

do-install:
	@${MKDIR} ${BINDIR}
.for f in ${PROGS}
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/Linux/x86/${f} ${BINDIR}/${f:R}
	@${INSTALL_SCRIPT} ${WRKDIR}/${f:R} ${PREFIX}/bin/linux-${f:R}
.endfor
.if defined(WITH_PUNKBUSTER)
	@${CP} -Rp ${WRKSRC}/pb ${DATADIR}
	@${RM} ${DATADIR}/pb/PB_EULA.txt
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README-linux.txt ${DOCSDIR}
	@${CP} -Rp ${WRKSRC}/Docs/LinuxFAQ ${DOCSDIR}
.   if defined(WITH_PUNKBUSTER)
	@${CP} -Rp ${WRKSRC}/Docs/PunkBuster ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/pb/PB_EULA.txt ${DOCSDIR}/PunkBuster
.   endif
.endif

.include <bsd.port.post.mk>
