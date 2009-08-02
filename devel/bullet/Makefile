# New ports collection makefile for:	bullet
# Date created:		2008-01-09
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bullet
PORTVERSION=	2.73
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/$/-sp1/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	acm@FreeBSD.org
COMMENT=	3D collision detection and rigid body dynamics library

BUILD_DEPENDS=	jam:${PORTSDIR}/devel/jam

USE_AUTOTOOLS=	automake:15:env autoconf:262:env libtool:22:env
GNU_CONFIGURE=	yes
USE_DOS2UNIX=	yes
USE_GL=		glu glut
USE_XORG=	x11

CONFIGURE_ARGS=		--x-includes=${LOCALBASE}/include
CONFIGURE_ENV=		CPPFLAGS=${CPPFLAGS} LDFLAGS=${LDFLAGS}

CPPFLAGS+=	-I${LOCALBASE}/include

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

JAM_CMD=	${LOCALBASE}/bin/jam
JAM_ARGS=	-qa

.include <bsd.port.pre.mk>

.if (${ARCH} == "amd64") || (${ARCH} == "ia64")
CFLAGS+=	-DUSE_ADDR64
.endif

.if ${ARCH} == "sparc64"
IGNORE=		Does not configure on sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%AUTOHEADER%%|${AUTOHEADER}|g" -e "s|%%AUTOCONF%%|${AUTOCONF}|g" -e \
		"s|%%ACLOCAL%%|${ACLOCAL}|g" -e "s|%%LIBTOOLIZE%%|${LIBTOOLIZE}|g" -e \
			"s|%%AUTOMAKE%%|${AUTOMAKE}|g" ${WRKSRC}/autogen.sh
	@${REINPLACE_CMD} -e "s|(libdir)|(prefix)/libdata|g" -e 63,64d ${WRKSRC}/Jamfile.in
	@${REINPLACE_CMD} -e "s|-O3||g" ${WRKSRC}/Jamrules

pre-configure:
	@cd ${WRKSRC} && ${SH} autogen.sh

post-configure:
	@${REINPLACE_CMD} -i "" -e 's,-lpthread,${PTHREAD_LIBS},g' ${WRKSRC}/Jamconfig

do-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${JAM_CMD} ${JAM_ARGS}

do-install:
	@cd ${WRKSRC} && \
		${JAM_CMD} install

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.pdf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}/CHANGELOG
.endif

.include <bsd.port.post.mk>
