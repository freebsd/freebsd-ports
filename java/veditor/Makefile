# New ports collection makefile for:	veditor
# Date created:				19 Oct 2006
# Whom:					lon_kamikaze@gmx.de
#
# $FreeBSD$
#

PORTNAME=	veditor
PORTVERSION=	0.7.1
CATEGORIES=	java cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20runtime/VEditor%20${PORTVERSION}
DISTNAME=	net.sourceforge.${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	A Verilog and VHDL editor plugin for eclipse

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse

OPTIONS=	VERILOG "Support Verilog with Icarus Verilog" On \
		VHDL "Support VHDL with FreeHDL" On

.include <bsd.port.options.mk>

.if defined(WITH_VERILOG)
RUN_DEPENDS+=	iverilog:${PORTSDIR}/cad/iverilog
.endif

.if defined(WITH_VHDL)
RUN_DEPENDS+=	freehdl-v2cc:${PORTSDIR}/cad/freehdl
.endif

PLIST_SUB=	VER=${PORTVERSION}

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

ECLIPSE=	${PREFIX}/eclipse
PLUGINS=	plugins

do-install:
	@${MKDIR} ${ECLIPSE}/${PLUGINS}
	@${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${ECLIPSE}/${PLUGINS}/

.include <bsd.port.mk>
