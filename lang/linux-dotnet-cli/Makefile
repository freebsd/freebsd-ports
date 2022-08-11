PORTNAME=	dotnet-cli
DISTNAME=	dotnet-runtime-${DISTVERSION}-linux-x64

USE_LINUX=

DISTINFO_FILE=	${MASTERDIR}/distinfo
PLIST_FILES=	bin/dotnet ${DATADIR}/dotnet
PKGMESSAGE=	${.CURDIR}/pkg-message
MASTERDIR=	${.CURDIR}/../linux-dotnet-runtime

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/dotnet ${STAGEDIR}${DATADIR}/dotnet
	${RLN} ${STAGEDIR}${DATADIR}/dotnet ${STAGEDIR}${PREFIX}/bin/dotnet

.include "${MASTERDIR}/Makefile"
