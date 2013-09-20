# Created by: lon_kamikaze@gmx.de
# $FreeBSD$

PORTNAME=	veditor
PORTVERSION=	0.7.1
PORTREVISION=	2
CATEGORIES=	java cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20runtime/VEditor%20${PORTVERSION}
DISTNAME=	net.sourceforge.${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	Verilog and VHDL editor plugin for eclipse

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse

OPTIONS_DEFINE=	VERILOG VHDL
VERILOG_DESC=	Support Verilog with Icarus Verilog
VHDL_VHDL=	Support VHDL with FreeHDL
OPTIONS_DEFAULT=	VERILOG VHDL

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVERILOG}
RUN_DEPENDS+=	iverilog:${PORTSDIR}/cad/iverilog
.endif

.if ${PORT_OPTIONS:MVHDL}
RUN_DEPENDS+=	freehdl-v2cc:${PORTSDIR}/cad/freehdl
.endif

PLIST_SUB=	VER=${PORTVERSION} \
		ECLIPSE=${ECLIPSE}

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

ECLIPSE=	lib/eclipse
PLUGINS=	plugins

do-install:
	@${MKDIR} ${PREFIX}/${ECLIPSE}/${PLUGINS}
	@${INSTALL_DATA} ${DISTDIR}/${DISTFILES} \
		${PREFIX}/${ECLIPSE}/${PLUGINS}/

.include <bsd.port.mk>
