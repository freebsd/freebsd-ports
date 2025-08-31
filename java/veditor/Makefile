PORTNAME=	veditor
PORTVERSION=	1.2.2
PORTREVISION=	6
CATEGORIES=	java cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20runtime/VEditor%20${PORTVERSION}
DISTNAME=	net.sourceforge.${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Verilog editor plugin for eclipse
WWW=		http://veditor.sourceforge.net/

RUN_DEPENDS=	eclipse:java/eclipse

OPTIONS_DEFINE=	VERILOG
VERILOG_DESC=	Support Verilog with Icarus Verilog
OPTIONS_DEFAULT=	VERILOG

VERILOG_RUN_DEPENDS=	iverilog:cad/iverilog

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
