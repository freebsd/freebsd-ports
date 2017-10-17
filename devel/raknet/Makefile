# Created by: Andrew Baznikin <dikiy@scn.ru>
# $FreeBSD$

PORTNAME=	raknet
PORTVERSION=	3.9.2
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	devel net
MASTER_SITES=	http://www.jenkinssoftware.com/raknet/downloads/ \
		LOCAL/martymac
DISTNAME=	RakNet-3.902

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Networking API that provides reliable UDP primarily for online games

# Original license is Indy license, but FreeBSD has been granted special
# authorization to provide RakNet 3.x (*only*, not 4.x) under the terms of
# the GPL v3 license. This agreement has been received by the MAINTAINER
# through a private mail exchange on 2012-03-20 (see files/SpecialAuth.mbox).
LICENSE=	GPLv3 SpecialAuth
LICENSE_COMB=	dual
LICENSE_NAME_SpecialAuth=	Special authorization from developer
LICENSE_FILE_SpecialAuth=	${FILESDIR}/SpecialAuth.mbox
LICENSE_PERMS_SpecialAuth=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LEGAL_TEXT=	Special authorization granted to distribute version 3.x under GPLv3

NOT_FOR_ARCHS=		aarch64 mips mips64
NOT_FOR_ARCHS_REASON=	fails to compile: error: Add your platform to the list

NO_WRKSUBDIR=	yes

USE_LDCONFIG=	yes
USE_GCC=	any

USES=		dos2unix cmake zip
DOS2UNIX_REGEX=	.*\.(cpp|h|txt)

# XXX Do not provide Samples for the following reason :
# - potential licensing problems
# XXX Disable build of DependentExtensions for the following reasons :
# - potential licensing problems
# - only static libraries are built (shared libraries are no more provided, e.g.
#   for autopatcher or rakvoice)
# - no install target is provided, which prevents us to determine what files
#   have to be provided by the port to have working extensions
CMAKE_ARGS+=	-DDISABLEDEPENDENCIES:BOOL=ON

OPTIONS_DEFINE=	DOCS

post-patch:
	@${FIND} ${WRKSRC} -type f -a '(' -name '*.cpp' -o -name '*.h' ')' -print0 \
		| ${XARGS} -0 -x -n10 \
			${REINPLACE_CMD} -e 's|Usage of RakNet is subject to the appropriate license agreement|Raknet is available under the terms of the GPLv3 license, see ${_LICENSE_DIR}/GPLv3|'

pre-install:
	@${FIND} ${WRKSRC} -type f -name '*.bak' -print0 \
		| ${XARGS} -0 -x -n10 ${RM}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/raknet
	(cd ${WRKSRC}/Source/ && ${COPYTREE_SHARE} \*.h ${STAGEDIR}${PREFIX}/include/raknet)
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/Lib/DLL/libRakNetDynamic.so \
		${STAGEDIR}${PREFIX}/lib/libraknet.so.0
	${LN} -sf ${PREFIX}/lib/libraknet.so.0 ${STAGEDIR}${PREFIX}/lib/libraknet.so
	${INSTALL_DATA} ${WRKSRC}/Lib/LibStatic/libRakNetStatic.a \
		${STAGEDIR}${PREFIX}/lib/libraknet.a
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/Help
	(cd ${WRKSRC}/Help/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/Help)
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
