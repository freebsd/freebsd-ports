# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	leocad
PORTVERSION=	0.79.3
CATEGORIES=	cad
MASTER_SITES=	GOOGLE_CODE
DISTFILES=	${PORTNAME}-${PORTVERSION}-src.tgz ${LEOCAD_PIECES}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}-src.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CAD modeling with LEGO-like bricks

EXTRACT_DEPENDS=${UNZIP_CMD}:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GL=		gl
USE_GNOME=	gtk20
USE_PKGCONFIG=	build
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		leocad.1

LEOCAD_PIECES=	pieces-7114.zip

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

post-extract:
	@${UNZIP_CMD} -q -o ${DISTDIR}/${DIST_SUBDIR}/${LEOCAD_PIECES} \
		-d ${WRKDIR}/pieces

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/config.mk
	@${REINPLACE_CMD} -e \
		's|+= -g|+=| ; \
		 s|@$$(CXX)|$$(CXX)| ; \
		 s|@install -c -m 0755|$${BSD_INSTALL_PROGRAM}| ; \
		 s|@install -c -m 0644|$${BSD_INSTALL_DATA}| ; \
		 s|share/man|man|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|-ldl||' ${WRKSRC}/common/module.mk

do-configure:
	(cd ${WRKSRC} && ${SETENV} PREFIX="${PREFIX}" ${GMAKE} config)

post-install:
	(cd ${WRKDIR}/pieces && ${INSTALL_DATA} * ${DATADIR})

.include <bsd.port.post.mk>
