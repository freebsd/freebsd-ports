# New ports collection makefile for:	veditor
# Date created:				19 Oct 2006
# Whom:					lon_kamikaze@gmx.de
#
# $FreeBSD$
#

PORTNAME=	veditor
PORTVERSION=	0.5.0
CATEGORIES=	java cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	net.sourceforge.${PORTNAME}_${PORTVERSION}

MAINTAINER=	lon_kamikaze@gmx.de
COMMENT=	A Verilog and VHDL editor plugin for eclipse

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse

.if defined(WITH_VERILOG)
RUN_DEPENDS+=	iverilog:${PORTSDIR}/cad/iverilog
.endif

.if defined(WITH_VHDL)
RUN_DEPENDS+=	freehdl-v2cc:${PORTSDIR}/cad/freehdl
.endif

OPTIONS=	VERILOG "Support Verilog with Icarus Verilog" On \
		VHDL "Support VHDL with FreeHDL" On

PLIST_SUB=	VER=${PORTVERSION}

NO_BUILD=	yes
USE_ZIP=	yes
NO_WRKSUBDIR=	yes

ECLIPSE=	${PREFIX}/eclipse
PLUGINS=	plugins

do-install:
	@${MKDIR} ${ECLIPSE}/${PLUGINS}
	@${CP} -r ${WRKSRC}/${PLUGINS}/* ${ECLIPSE}/${PLUGINS}/

plist: build
	@${ECHO} "===>  Rebuilding PLIST."
	@${TOUCH} ${PLIST}
	@${RM} ${PLIST}
	@${FIND} -d ${WRKSRC}/${PLUGINS}/ -not -type d \
		| ${SED} "s|${WRKSRC}|eclipse|1" \
		| ${SED} "s|${PORTVERSION}|%%VER%%|g" \
		>> ${PLIST}
	@${FIND} -d ${WRKSRC}/${PLUGINS}/ -mindepth 1 -type d \
		| ${SED} "s|${WRKSRC}|@dirrm eclipse|1" \
		| ${SED} "s|${PORTVERSION}|%%VER%%|g" \
		>> ${PLIST}
	@${ECHO} "@dirrmtry eclipse/${PLUGINS}" >> ${PLIST}
	@${ECHO} "@dirrmtry eclipse" >> ${PLIST}

.include <bsd.port.mk>
