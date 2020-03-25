# $FreeBSD$

PORTNAME=	qflow
DISTVERSION=	1.4.79
PORTREVISION=	1
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	End-to-end digital synthesis flow for ASIC designs

LICENSE=	GPLv2

APP_DEPENDS=	graywolf:cad/graywolf \
		magic>0:cad/magic \
		netgen-lvs>0:cad/netgen-lvs \
		qrouter>0:cad/qrouter \
		sta:cad/opensta \
		yosys>0:cad/yosys
BUILD_DEPENDS=	${APP_DEPENDS}
RUN_DEPENDS=	${APP_DEPENDS}

USES=		gmake python tar:tgz tcl tk
USE_GITHUB=	yes
GH_ACCOUNT=	RTimothyEdwards

GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|^#!ENV_PATH python3$$|#!${PYTHON_CMD}|' ${WRKSRC}/scripts/*.py.in
	@${REINPLACE_CMD} -e 's|^#!TCLSH_PATH$$|#!${TCLSH}|' ${WRKSRC}/scripts/*.tcl.in

post-install:
	@cd ${STAGEDIR}${PREFIX}/share/qflow/bin && \
		${STRIP_CMD} vlog2Spice vlog2Verilog vlog2Def vlog2Cel vlogFanout DEF2Verilog addspacers vesta spice2delay rc2dly blif2BSpice blif2Verilog blifFanout && \
		${RM} yosys-abc && ${LN} -s ${LOCALBASE}/bin/abc yosys-abc # https://github.com/RTimothyEdwards/qflow/issues/6

.include <bsd.port.mk>
