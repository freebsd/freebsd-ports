PORTNAME=	molden
DISTVERSION=	7.1
PORTEPOCH=	1
CATEGORIES=	biology
MASTER_SITES=	https://ftp.science.ru.nl/Molden/
DISTNAME=	${PORTNAME}${DISTVERSION}

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Display molecular orbitals and electron densities in 2D and 3D

LICENSE=	Molden
LICENSE_NAME=	Molden License
LICENSE_FILE=	${WRKSRC}/CopyRight
LICENSE_PERMS=	auto-accept dist-mirror pkg-mirror # free for academic, non profit use

BUILD_DEPENDS=	makedepend:devel/makedepend

USES=		fortran gl gmake xorg
USE_XORG=	x11 xmu
USE_GL=		gl glu

MAKEFILE=	makefile

CFLAGS+=	-D${OPSYS:tu} -DDOBACK -DHASTIMER -DCOLOR_OFFSET=0.0 \
		-I${LOCALBASE}/include -Wno-return-type

PORTDOCS=	*
PORTDATA=	*

PLIST_FILES=	bin/ambfor \
		bin/ambmd \
		bin/gmolden \
		bin/molden \
		bin/surf

PORTSCOUT=	limit:^5\.0\.

OPTIONS_DEFINE=		DATA DOCS
OPTIONS_DEFAULT=	DATA

post-extract:
	# remove object modules
	@${FIND} ${WRKSRC} -name "*.o" | ${XARGS} ${RM}
	# remove pre-built executables
	@${RM} ${WRKSRC}/bin/*

post-configure:
	@${ECHO_MSG} "********************"
	@${ECHO_MSG} "**  If you want to use a larger MOLDEN,"
	@${ECHO_MSG} "**  edit change_parameter.sh and run it,"
	@${ECHO_MSG} "**  before \'make build\'."
	@${ECHO_MSG} "********************"

do-install:
.for e in molden gmolden ambfor ambmd surf
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${e} ${STAGEDIR}${PREFIX}/bin
.endfor

do-install-DATA-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/test
	(cd ${WRKSRC}/test && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/test)
	${MKDIR} ${STAGEDIR}${DATADIR}/utils
	(cd ${WRKSRC}/utils && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/utils)

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.pre.mk>

.if ${GCC_DEFAULT} >= 10
# workaround for Type mismatch between actual argument at (1) and actual argument at (2) (INTEGER(4)/REAL(4)).
# in theory, this should set FCFLAGS, but the port does not conform
FFLAGS+=	-fallow-argument-mismatch
.endif

.include <bsd.port.post.mk>
