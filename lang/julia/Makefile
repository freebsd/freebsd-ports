# Created by: Iblis Lin <iblis@hs.ntnu.edu.tw>
# $FreeBSD$

PORTNAME=	julia
PORTVERSION=	1.0.3
PORTREVISION=	3
CATEGORIES=	lang math
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	iblis@hs.ntnu.edu.tw
COMMENT=	Meta port for the different versions of Julia compiler

# LICENSE=	# empty
# LICENSE_FILE=	# empty

ONLY_FOR_ARCHS=	amd64 i386

NO_BUILD=	yes

PLIST_FILES=	bin/julia \
		man/man1/julia.1.gz\
		etc/julia

OPTIONS_DEFINE=	V10
OPTIONS_DEFAULT=	V${JULIA_DEFAULT:S/.//} D${JULIA_DEFAULT:S/.//}
OPTIONS_SINGLE=	DEFAULTVER
OPTIONS_SINGLE_DEFAULTVER=	D10  # D stands for default

V10_DESC=	Install v${:!${MAKE} -C ${PORTSDIR}/lang/julia10 -v PORTVERSION!} release \
	(1.x long-term support branch)

V10_RUN_DEPENDS=	julia10:lang/julia10

DEFAULTVER_DESC=	Select default version
D10_DESC=	Set up symbolic links of bin/julia, manual page and etc/startup.jl for 1.0

D10_IMPLIES=	V10

.include <bsd.port.options.mk>

_JULIA_VER=	${PORT_OPTIONS:MD*:S/D//}

do-install:
	${RLN} julia${_JULIA_VER} ${STAGEDIR}${PREFIX}/bin/julia
	${RLN} ../julia/julia${_JULIA_VER}/etc/julia ${STAGEDIR}${PREFIX}/etc
	${RLN} julia${_JULIA_VER}.1.gz ${STAGEDIR}${PREFIX}/man/man1/julia.1.gz

.include <bsd.port.mk>
