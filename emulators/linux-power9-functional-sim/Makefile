PORTNAME=	power9-functional-sim
PORTVERSION=	1.1
PORTREVISION=	1
DISTVERSIONSUFFIX=	-0.el7
CATEGORIES=	emulators linux
MASTER_SITES=	http://public.dhe.ibm.com/software/server/powerfuncsim/p9/packages/v1.1-0/

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	IBM POWER9 Functional Simulator (mambo) (CentOS ${LINUX_DIST_VER})

LICENSE=	IBMFUNCTIONALSIM
LICENSE_NAME=	IBM Functional Simulator License
LICENSE_FILE=	${WRKSRC}/opt/ibm/systemsim-p9/license/Softcopy/LA_en
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

ONLY_FOR_ARCHS=	amd64

USES=		linux:c7 perl5 shebangfix
SHEBANG_FILES=	opt/ibm/systemsim-p9/bin/systemsim
SHEBANG_GLOB=	*.sh *.pl
USE_LDCONFIG=	yes
USE_LINUX=	tcl85
USE_LINUX_RPM=	nolib
USE_PERL5=	run

BIN_DISTNAMES=	systemsim-p9-${DISTVERSION}${DISTVERSIONSUFFIX}
SRC_DISTFILES=

.include <bsd.port.mk>
