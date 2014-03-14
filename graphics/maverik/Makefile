# Created by: ijliao
# $FreeBSD$

PORTNAME=	maverik
PORTVERSION=	6.2
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://aig.cs.man.ac.uk/maverik/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Publicly available virtual reality (VR) system

DEPRECATED=	Unmaintained since 2001
EXPIRATION_DATE=	2014-04-12
USE_SUBMAKE=	yes
USE_GL=		yes
WANT_GNOME=	yes
SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		REALCURDIR="${.CURDIR}" \
		DISTNAME="${DISTNAME}"
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	setup
CONFIGURE_ARGS=	--MESAPATH=${LOCALBASE}
USE_LDCONFIG=	yes
MANCOMPRESSED=	no
MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	*

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png
CONFIGURE_ARGS+=	--PNGLIBS="-L${LOCALBASE}/lib -lpng" \
			--PNGINCL="-I${LOCALBASE}/include"
.endif

post-extract:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/genman3list.sh

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		-e 's|%%CC%%|${CC}|g' \
		-e 's|%%CXX%%|${CXX}|g' \
		-e 's|%%CFLAGS%%|${CFLAGS}|g' \
		-e 's|%%CXXFLAGS%%|${CXXFLAGS}|g' \
		-e 's|%%PTHREAD_CFLAGS%%|${PTHREAD_CFLAGS}|g'  \
		-e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g' ${WRKSRC}/setup

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/* ${PREFIX}/lib
	@${MKDIR} ${PREFIX}/include/maverik
	${INSTALL_DATA} ${WRKSRC}/incl/* ${PREFIX}/include/maverik
	${FIND} ${WRKSRC}/doc/MFS/man3 -name '*.3' -exec \
		${INSTALL_MAN} \{} ${MAN3PREFIX}/man/man3 \;

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}/MFS
	@(cd ${WRKSRC}/doc/MFS && ${COPYTREE_SHARE} "html pdf ps" ${DOCSDIR}/MFS)
	@${MKDIR} ${DOCSDIR}/MPG
	@(cd ${WRKSRC}/doc//MPG && ${COPYTREE_SHARE} "pdf ps" ${DOCSDIR}/MPG)
.endif

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

.include <bsd.port.mk>
