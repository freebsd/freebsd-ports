# Created by: lon_kamikaze@gmx.de
# $FreeBSD$

PORTNAME=	veditor
PORTVERSION=	1.2.2
CATEGORIES=	java cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20runtime/VEditor%20${PORTVERSION}
DISTNAME=	net.sourceforge.${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Verilog and VHDL editor plugin for eclipse

RUN_DEPENDS=	eclipse:java/eclipse

OPTIONS_DEFINE=	VERILOG VHDL
VERILOG_DESC=	Support Verilog with Icarus Verilog
VHDL_VHDL=	Support VHDL with FreeHDL
OPTIONS_DEFAULT=	VERILOG VHDL

VERILOG_RUN_DEPENDS=	iverilog:cad/iverilog
VHDL_RUN_DEPENDS=	freehdl-v2cc:cad/freehdl

PLIST_SUB=	VER=${PORTVERSION} \
		ECLIPSE=${ECLIPSE}

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

ECLIPSE=	lib/eclipse
PLUGINS=	plugins

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${ECLIPSE}/${PLUGINS}
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} \
		${STAGEDIR}${PREFIX}/${ECLIPSE}/${PLUGINS}

.include <bsd.port.mk>
