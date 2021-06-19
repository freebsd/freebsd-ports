# Created by: Ryo MIYAMOTO <rmiya@cc.hirosaki-u.ac.jp>

PORTNAME=	molden
DISTVERSION=	5.8.2
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.cmbi.umcn.nl/pub/molgraph/molden/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Display molecular orbitals and electron densities in 2D and 3D

LICENSE=	Molden
LICENSE_NAME=	Molden
LICENSE_FILE=	${WRKSRC}/CopyRight
# free for academic, non profit usage; do not re-distribute source and executable.
LICENSE_PERMS=	auto-accept

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:R}

USES=		fortran gl gmake xorg
USE_XORG=	x11
USE_GL=		gl glu
MAKEFILE=	makefile
MAKE_JOBS_UNSAFE=yes

CFLAGS+=	-D${OPSYS:tu} -DDOBACK -DHASTIMER -DCOLOR_OFFSET=0.0 \
		-I${LOCALBASE}/include -Wno-return-type

PORTDOCS=	*
PORTDATA=	*
PLIST_FILES=	bin/ambfor bin/gmolden bin/molden bin/surf

PORTSCOUT=	limit:^5\.0\.

OPTIONS_DEFINE=		DATA DOCS
OPTIONS_DEFAULT=	DATA

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CC |#CC | ; \
		 s|^FC |#FC | ; \
		 s|/usr/X11R6|${LOCALBASE}| ; \
		 s|$$(LIBS)|$$(LIBS) $$(LDFLAGS)| ; \
		 s|-lXmu|| ; \
		 /depend/s|^|#|' ${WRKSRC}/makefile

post-configure:
	@${ECHO_MSG} "********************"
	@${ECHO_MSG} "**  If you want to use a larger MOLDEN,"
	@${ECHO_MSG} "**  edit change_parameter.sh and run it,"
	@${ECHO_MSG} "**  before \'make build\'."
	@${ECHO_MSG} "********************"

do-install:
.for i in molden gmolden
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${i} ${STAGEDIR}${PREFIX}/bin)
.endfor
.for i in ambfor surf
	(cd ${WRKSRC}/${i} && ${INSTALL_PROGRAM} ${i} ${STAGEDIR}/${PREFIX}/bin)
.endfor

do-install-DATA-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/test
	(cd ${WRKSRC}/test && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/test)
	${MKDIR} ${STAGEDIR}${DATADIR}/utils
	(cd ${WRKSRC}/utils && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/utils)

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.pre.mk>

.if ${GCC_DEFAULT} >= 10
# workaround for Type mismatch between actual argument at (1) and actual argument at (2) (INTEGER(4)/REAL(4)).
# in theory, this should set FCFLAGS, but the port does not conform
FFLAGS+=	-fallow-argument-mismatch
.endif

.include <bsd.port.post.mk>
