PORTNAME=	cli
DISTVERSION=	3.6.3
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Helpers for Developing Command Line Interfaces
WWW=		https://cran.r-project.org/web/packages/cli/

LICENSE=	MIT

USES=		cran:auto-plist,compiles

post-install:
	@${ECHO_CMD} "@dir ${R_MOD_DIR}/help/figures" >> ${TMPPLIST}

.include <bsd.port.mk>
