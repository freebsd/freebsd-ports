# $FreeBSD$

PORTNAME=	qflow
DISTVERSION=	1.4.79
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	End-to-end digital synthesis flow for ASIC designs

LICENSE=	GPLv2

APP_DEPENDS=	magic>0:cad/magic \
		netgen-lvs>0:cad/netgen-lvs \
		qrouter>0:cad/qrouter \
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
		${STRIP_CMD} a* b* D* r* s* v* && \
		${RM} yosys-abc && ${LN} -s ${LOCALBASE}/bin/abc yosys-abc # https://github.com/RTimothyEdwards/qflow/issues/6

.include <bsd.port.mk>
