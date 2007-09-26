# New ports collection makefile for:	sauerbraten
# Date created:		2006-02-01
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	sauerbraten
PORTVERSION=	20070415
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_2007_04_15_spring_edition_linux

MAINTAINER=	acm@FreeBSD.org
COMMENT=	First person shooter based on Cube

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
CONFIGURE_ENV=	ACLOCAL=true AUTOCONF=true AUTOMAKE=true
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_WRKSRC=	${WRKSRC}/src/enet
MAKE_ENV+=	CXX="${CXX}"
BUILD_WRKSRC=	${WRKSRC}/src
WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	libenet

OPTIONS=	CLIENT "Build client" on \
		DEDICATED "Build dedicated server" on

SUB_FILES=	sauer_client sauer_server pkg-message

SAUDATDIR=	packages data

.include <bsd.port.pre.mk>

.if defined(WITHOUT_CLIENT) && defined(WITHOUT_DEDICATED)
IGNORE=		needs at least one executable (CLIENT or DEDICATED)
.endif

.if ${OSVERSION} < 500000
BROKEN=		does not compile
.endif

.if !defined(WITHOUT_CLIENT)
USE_GL=		yes
USE_SDL=	image mixer sdl
ALL_TARGET+=	client
PLIST_SUB+=	CLIENT=""
SAUER_BIN+=	client
.else
PLIST_SUB+=	CLIENT=""
.endif

.if !defined(WITHOUT_DEDICATED)
ALL_TARGET+=	server
PLIST_SUB+=	DEDICATED=""
SAUER_BIN+=	server
.else
PLIST_SUB+=	DEDICATED=""
.endif

post-extract:
	@${FIND} ${WRKSRC} -type d -name CVS -type d -print0 | \
		${XARGS} -0 ${RM} -R

post-patch:
	@${REINPLACE_CMD} -Ee '/^#define (HAS_GETHOSTBY(NAME|ADDR)_R) 1/d' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
.for f in ${SAUER_BIN}
	${INSTALL_SCRIPT} ${WRKDIR}/sauer_${f} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/sauer_${f} ${PREFIX}/libexec
.endfor
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && \
		${FIND} -E ${SAUDATDIR} -type d -exec ${MKDIR} "${DATADIR}/{}" \; && \
		${FIND} -E ${SAUDATDIR} -type f -iregex ".*\.(png|cfg|cgz|jpg|ogg|ogz|txt|mid|md2|md3|ms3d|qc|wav)" \
			-exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs && \
		${FIND} -E * -type d -exec ${MKDIR} "${DOCSDIR}/{}" \; && \
		${FIND} -E * -type f -iregex ".*\.(html|css|jpg)" -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/{}" \;
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
