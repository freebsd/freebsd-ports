PORTNAME=	netgen
DISTVERSION=	1.5.305
CATEGORIES=	cad
PKGNAMESUFFIX=	-lvs

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool for comparing netlists (a process known as LVS)
WWW=		http://opencircuitdesign.com/netgen/

LICENSE=	GPLv1
LICENSE_FILE=	${WRKSRC}/Copying

RUN_DEPENDS=	bash:shells/bash

USES=		gmake python shebangfix tk xorg
USE_GITHUB=	yes
GH_ACCOUNT=	RTimothyEdwards
USE_XORG=	x11

SHEBANG_FILES=	python/*.py python/*.py.in tcltk/netgen.sh.in

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-interpreter=tcl \
		--with-tcl=${TCL_LIBDIR} \
		--with-tk=${TK_LIBDIR} \
		--with-x
CONFIGURE_ENV=	HAVE_PYTHON3=yes

CONFLICTS_INSTALL=	netgen # bin/netgen

post-install:
	@cd ${STAGEDIR}${PREFIX}/lib/netgen/tcl && \
		${STRIP_CMD} netgenexec tclnetgen.so

.include <bsd.port.mk>
