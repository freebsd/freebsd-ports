# New ports collection makefile for:	cvsgraph
# Date created:				2001-02-21
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	cvsgraph
PORTVERSION=	1.1.1
CATEGORIES=	devel graphics
MASTER_SITES=	http://www.akhphd.au.dk/~bertho/cvsgraph/release/

MAINTAINER=	trevor@FreeBSD.org

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison
LIB_DEPENDS=	gd.2:${PORTSDIR}/graphics/gd \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.4:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		cvsgraph.1
MAN5=		cvsgraph.conf.5

ALL_TARGET=	cvsgraph
DOCDIR=		share/doc/${PORTNAME}
DOCS=		ChangeLog LICENCE README
PLIST=		${WRKDIR}/pkg-plist
USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gd-inc=${LOCALBASE}/include/gd \
		--with-gd-lib=${LOCALBASE}/lib \
		--with-png=${LOCALBASE} \
		--with-z-inc=/usr/include \
		--with-z-lib=/usr/lib

post-configure:
	${PERL} -pi -e \
		"s|CFLAGS	=|CFLAGS += -I${LOCALBASE}/include \
		-I${LOCALBASE}/include/gd|g" \
		${WRKSRC}/Makefile

pre-install:
	${ECHO} bin/cvsgraph > ${PLIST}
	${ECHO} etc/cvsgraph.conf >> ${PLIST}
.if !defined(NOPORTDOCS)
.for i in ${DOCS}
	${ECHO} ${DOCDIR}/${i} >> ${PLIST}
.endfor
	${ECHO} @dirrm ${DOCDIR} >> ${PLIST}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/cvsgraph.conf ${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/cvsgraph.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/cvsgraph.conf.5 ${PREFIX}/man/man5
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/${DOCDIR}
.endfor
.endif

.include <bsd.port.mk>
