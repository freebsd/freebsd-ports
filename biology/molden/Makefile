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

USES=		fortran gmake
USE_XORG=	x11 xproto
USE_GL=		glu
MAKEFILE=	makefile
MAKE_JOBS_UNSAFE=yes

CFLAGS+=	-D${OPSYS:U} -DDOBACK -DHASTIMER -DCOLOR_OFFSET=0.0 \
		-I/usr/local/include -Wno-return-type

PORTDOCS=	*
PORTDATA=	*
PLIST_FILES=	bin/ambfor bin/gmolden bin/molden bin/surf

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
	${INSTALL_PROGRAM} ${WRKSRC}/molden ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/gmolden ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ambfor/ambfor ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/surf/surf ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MDATA}
	${MKDIR} ${STAGEDIR}${DATADIR}/test
	${INSTALL_DATA} ${WRKSRC}/test/* ${STAGEDIR}${DATADIR}/test
	${MKDIR} ${STAGEDIR}${DATADIR}/utils
	${INSTALL_DATA} ${WRKSRC}/utils/* ${STAGEDIR}${DATADIR}/utils
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
