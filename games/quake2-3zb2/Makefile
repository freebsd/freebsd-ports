PORTNAME=	3zb2
PORTVERSION=	0.97
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.angelfire.com/mt2/quakebots/:prog \
		http://ponpoko.tri6.net/3zb2/routes/:routes
PKGNAMEPREFIX=	${Q2PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tu}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:prog \
		${PORTNAME}src${PORTVERSION:S/0.//}${EXTRACT_SUFX}:prog
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	3rd Zigock II bots for Quake II

USES=		dos2unix zip
DOS2UNIX_FILES=	*.[ch]
NO_WRKSUBDIR=	yes
SUB_FILES=	pkg-message

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

OPTIONS_DEFINE=	ROUTES DOCS
OPTIONS_DEFAULT=	ROUTES
OPTIONS_SUB=	yes

ROUTES_DESC=	Install routes for DM and CTF maps (recommended)

.include "${.CURDIR}/../quake2-data/Makefile.include"
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MROUTES}
ROUTES=		base_pk chflm2130_pk chfxmap0109_pk citycl_pk cmbbstr_pk \
		cxdmx_pk cxxdmx_pk dm64_pk fact_pk hangar_pk ikdmx_pk \
		ikdmx_pk2 jail_pk q2dmx_pk retinal_pk spasmox_pk trdmx_pk \
		trpower_pk verm0x_pk ware_pk waste_pk xatrixmap_pk1 \
		xatrixmap_pk2 xatrixmap_pk3 xatrixmap_pk4 xdm3 xdmx_pk \
		xldmx_pk ztn2dmx_pk

.for f in ${ROUTES}
DISTFILES+=	${f}${EXTRACT_SUFX}:routes
.endfor
.endif

post-extract:
# Rename files and directories to lower case
	@cd ${WRKSRC}; for f in *; do \
	    ${MV} $${f} `${ECHO_CMD} $${f} | ${TR} '[:upper:]' '[:lower:]'`; \
	done
	@${CP} ${FILESDIR}/${MAKEFILE} ${WRKSRC}

do-install:
.for f in chctf chdtm
	@${MKDIR} ${STAGEDIR}${Q2DIR}/${PORTNAME}/${f}
	${INSTALL_DATA} ${WRKSRC}/3zb2/${f}/* \
		${STAGEDIR}${Q2DIR}/${PORTNAME}/${f}
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/game.so \
		${STAGEDIR}${Q2DIR}/${PORTNAME}
	cd ${WRKSRC}/3zb2 && ${INSTALL_DATA} *.cfg 3ZBMaps.lst pak6.pak \
		${STAGEDIR}${Q2DIR}/${PORTNAME}
.if ${PORT_OPTIONS:MROUTES}
	${INSTALL_DATA} ${WRKSRC}/*.chn ${STAGEDIR}${Q2DIR}/${PORTNAME}/chdtm
	${INSTALL_DATA} ${WRKSRC}/*.chf ${STAGEDIR}${Q2DIR}/${PORTNAME}/chctf
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/3zb2 && ${CP} -a *.txt "User Guide" ${STAGEDIR}${DOCSDIR}
	@${FIND} ${STAGEDIR}${DOCSDIR} -type d -print0 | \
		${XARGS} -0 ${CHMOD} ${BINMODE}
	@${FIND} ${STAGEDIR}${DOCSDIR} -type f -print0 | \
		${XARGS} -0 ${CHMOD} ${SHAREMODE}

.include <bsd.port.mk>
