PORTNAME=	power10-functional-sim
PORTVERSION=	1.1
DISTVERSIONSUFFIX=	-0.rhel7
CATEGORIES=	emulators linux
MASTER_SITES=	http://public.dhe.ibm.com/software/server/powerfuncsim/p10/packages/v1.1-0/

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	IBM POWER10 Functional Simulator (mambo) (CentOS ${LINUX_DIST_VER})

LICENSE=	IBMFUNCTIONALSIM
LICENSE_NAME=	IBM Functional Simulator License
LICENSE_FILE=	${FILESDIR}/LA_en.txt
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

ONLY_FOR_ARCHS=	amd64

USES=		linux:c7 perl5 shebangfix
SHEBANG_FILES=	opt/ibm/systemsim-p10-1.1-0/bin/systemsim
SHEBANG_GLOB=	*.sh *.pl
USE_LDCONFIG=	yes
USE_LINUX=	tcl85
USE_LINUX_RPM=	nolib
USE_PERL5=	run

BIN_DISTNAMES=	systemsim-p10-${DISTVERSION}${DISTVERSIONSUFFIX}
SRC_DISTFILES=

.include <bsd.port.mk>
