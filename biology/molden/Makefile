# Created by: Ryo MIYAMOTO <rmiya@cc.hirosaki-u.ac.jp>
# $FreeBSD$

PORTNAME=	molden
PORTVERSION=	5.0.6
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.cmbi.ru.nl/pub/molgraph/molden/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display molecular orbitals and electron densities in 2D and 3D

RESTRICTED=	free for academic, non profit usage; do not re-distribute source and executable.

OPTIONS_DEFINE=	DATA DOCS
OPTIONS_DEFAULT=DATA

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:R}

USE_XORG=	x11
USE_GL=		glu
USE_FORTRAN=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile
MAKE_JOBS_UNSAFE=yes

CFLAGS+=	-D${OPSYS:U} -DDOBACK -DHASTIMER -DCOLOR_OFFSET=0.0

PORTDOCS=	*
PORTDATA=	*
PLIST_FILES=	bin/ambfor bin/gmolden bin/molden bin/surf

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CC |#CC | ; \
		 s|^FC |#FC | ; \
		 s|/usr/X11R6|${LOCALBASE}| ; \
		 s|-lXmu|| ; \
		 /depend/s|^|#|' ${WRKSRC}/makefile

post-configure:
	@${ECHO_MSG} "********************"
	@${ECHO_MSG} "**  If you want to use a larger MOLDEN,"
	@${ECHO_MSG} "**  edit change_parameter.sh and run it,"
	@${ECHO_MSG} "**  before \'make build\'."
	@${ECHO_MSG} "********************"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/molden ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/gmolden ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ambfor/ambfor ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/surf/surf ${PREFIX}/bin
.if ${PORT_OPTIONS:MDATA}
	@${MKDIR} ${DATADIR}/test
	${INSTALL_DATA} ${WRKSRC}/test/* ${DATADIR}/test
	@${MKDIR} ${DATADIR}/utils
	${INSTALL_DATA} ${WRKSRC}/utils/* ${DATADIR}/utils
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
